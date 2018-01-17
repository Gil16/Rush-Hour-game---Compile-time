#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

#include "BoardCell.h"
#include "GameBoard.h"
#include "TransposeList.h"


template<CellType T, Direction D, int N>
struct Move{
    static_assert(T != EMPTY, "The Car type you enter was EMPTY, and it's not allowed!");
    constexpr static CellType type = T;
    constexpr static Direction direction = D;
    constexpr static int amount = N;
};

template<typename L, CellType CURRTYPE, CellType CARTYPE, int N>
struct FindFirstInstanceOfACar{
    constexpr static int first = FindFirstInstanceOfACar<typename L::next, L::head::type, CARTYPE, N+1>::first;
};

template<typename L , CellType T, int N>
struct FindFirstInstanceOfACar<List<L>, T, T, N>{
    constexpr static int first = N;
};


// Here we check if we can move the STEPS amount, only if all the STEPS are EMPTY.
// The structure is meant for 2 cases: 1) for moving right 2) for moving left
// 1) The LOCATION is the beginning of the car location, and then we will check the number of STEPS to it's new location.
// 2) The LOCATION is the end of the new location of the car, and then we will check the number of STEPS to the right.
template<typename T, int LOCATION, int STEPS, CellType TYPE>
struct CheckMove{
    typedef typename CheckMove< typename T::next, LOCATION-1, STEPS, T::next::head::type >::value value;
};

template<typename T, int STEPS>
struct CheckMove<List<T>, 0, STEPS, EMPTY>{
    typedef typename CheckMove<typename T::next, 0, STEPS-1, T::next::head::type>::value value;
};

template<typename T, int STEPS, CellType TYPE>
struct CheckMove<List<T>, 0, STEPS, TYPE>{
    constexpr static bool value = false;
};

template<typename T>
struct CheckMove<List<T>, 0, 1, EMPTY>{
    constexpr static bool value = true;
};

// LOCATION here is the first instance of the car on the LEFT
template<typename T, int LOCATION, int LENGTH, Direction D>
struct OneMove{
    typedef typename GetAtIndex<LOCATION, T>::value CurrentCell;
    typedef typename SetAtIndex<LOCATION, BoardCell<EMPTY, UP, 0>, typename SetAtIndex<LOCATION+LENGTH, CurrentCell,
            T >::list >::list list;
};

template<typename T, int LOCATION, int LENGTH>
struct OneMove<T, LOCATION, LENGTH, LEFT>{
    typedef typename GetAtIndex<LOCATION, T>::value CurrentCell;
    typedef typename SetAtIndex<LOCATION+LENGTH, BoardCell<EMPTY, UP, 0> , typename SetAtIndex<LOCATION-1, CurrentCell ,
            T >::list >::list list;
};


template<typename T, int LOCATION ,int STEPS, int LENGTH, Direction D>
struct ManyMoves{
    typedef typename ManyMoves<typename OneMove<T, LOCATION, LENGTH, D>::list, LOCATION+1, STEPS-1, LENGTH, RIGHT >::list list;
};

template<typename T, int LOCATION ,int STEPS, int LENGTH>
struct ManyMoves<T, LOCATION, STEPS, LENGTH, LEFT>{
    typedef typename ManyMoves<typename OneMove<T, LOCATION, LENGTH, LEFT>::list, LOCATION-1, STEPS-1, LENGTH, LEFT >::list list;
};

template<typename T, int LOCATION, int LENGTH, Direction D>
struct ManyMoves<T, LOCATION, 0, LENGTH, D>{
    typedef T list;
};


template<typename GB, int R, int C, Direction D, int A>
struct MoveVehicle{
    typedef typename GB::board tempBoard;
    static_assert((R >= tempBoard::length) || (R < 0), "The given Row number is incorrect");
    static_assert((C >= tempBoard::width) || (C < 0), "The given Col number is incorrect");
    static_assert(GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value>::value::type != EMPTY , "The given Cell is EMPTY");
    constexpr static int carDir = GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value >::value::direction;
    static_assert((carDir % 2) ? ((carDir == D) || ((carDir + 1) == D)) : ((carDir == D) || ((carDir - 1) == D)),
                  "The given direction is not the excpected");
    typedef typename Transpose<tempBoard>::matrix aBoard2;
    typedef typename GetAtIndex<C, aBoard2>::value getRow;
    constexpr static int firstInstance = FindFirstInstanceOfACar<getRow, getRow::head::type, GetAtIndex<R,getRow>::value::type,0>::first;
    static_assert(CheckMove<getRow, firstInstance+(GetAtIndex<R,getRow>::value::length), A, getRow::head::type>::value,
                  "You cannot move RIGHT, there is a car!");
    typedef typename SetAtIndex<C, typename ManyMoves<getRow, firstInstance, A,
            GetAtIndex<R, getRow>::value::length, LEFT>::list, aBoard2>::list newBoard1;
    typedef GameBoard<typename Transpose< newBoard1>::matrix> board;
};


template<typename GB, int R, int C, int A>
struct MoveVehicle<GB, R, C, RIGHT, A>{
    typedef typename GB::board tempBoard;
    static_assert((R >= tempBoard::length) || (R < 0), "The given Row number is incorrect");
    static_assert((C >= tempBoard::width) || (C < 0), "The given Col number is incorrect");
    static_assert(GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value>::value::type != EMPTY , "The given Cell is EMPTY");
    constexpr static int carDir = GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value >::value::direction;
    static_assert((carDir % 2) ? ((carDir == D) || ((carDir + 1) == D)) : ((carDir == D) || ((carDir - 1) == D)),
                                                                 "The given direction is not the excpected");
    typedef typename GetAtIndex<R, tempBoard>::value getRow;
    constexpr static int firstInstance = FindFirstInstanceOfACar<getRow, getRow::head::type, GetAtIndex<C,getRow>::value::type,0>::first;
    static_assert(CheckMove<getRow, firstInstance+(GetAtIndex<C,getRow>::value::length), A, getRow::head::type>::value,
                                                     "You cannot move RIGHT, there is a car!");
    typedef GameBoard< typename SetAtIndex<R, typename ManyMoves<getRow, firstInstance, A,
            GetAtIndex<C, getRow>::value::length, RIGHT>::list, tempBoard>::list> board;
};

template<typename GB, int R, int C, int A>
struct MoveVehicle<GB, R, C, LEFT, A>{
    typedef typename GB::board tempBoard;
    static_assert((R >= tempBoard::length) || (R < 0), "The given Row number is incorrect");
    static_assert((C >= tempBoard::width) || (C < 0), "The given Col number is incorrect");
    static_assert(GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value>::value::type != EMPTY , "The given Cell is EMPTY");
    constexpr static int carDir = GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value >::value::direction;
    static_assert((carDir % 2) ? ((carDir == D) || ((carDir + 1) == D)) : ((carDir == D) || ((carDir - 1) == D)),
                  "The given direction is not the excpected");

    typedef typename GetAtIndex<R, tempBoard>::value getRow;
    constexpr static int firstInstance = FindFirstInstanceOfACar<getRow, getRow::head::type, GetAtIndex<C,getRow>::value::type,0>::first;

    static_assert(CheckMove<getRow, firstInstance-A, A, getRow::head::type>::value, "You cannot move LEFT, there is a car!");
    typedef GameBoard< typename SetAtIndex<R, typename ManyMoves<getRow, firstInstance, A,
            GetAtIndex<C, getRow>::value::length, RIGHT>::list, tempBoard>::list> board;
};

template<typename GB, int R, int C, int A>
struct MoveVehicle<GB, R, C, DOWN, A>{
    typedef typename GB::board tempBoard;
    static_assert((R >= tempBoard::length) || (R < 0), "The given Row number is incorrect");
    static_assert((C >= tempBoard::width) || (C < 0), "The given Col number is incorrect");
    static_assert(GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value>::value::type != EMPTY , "The given Cell is EMPTY");
    constexpr static int carDir = GetAtIndex<C, typename GetAtIndex<R, tempBoard>::value >::value::direction;
    static_assert((carDir % 2) ? ((carDir == D) || ((carDir + 1) == D)) : ((carDir == D) || ((carDir - 1) == D)),
                  "The given direction is not the excpected");
    typedef typename Transpose<tempBoard>::matrix aBoard2;
    typedef typename GetAtIndex<C, aBoard2>::value getRow;
    constexpr static int firstInstance = FindFirstInstanceOfACar<getRow, getRow::head::type, GetAtIndex<R,getRow>::value::type,0>::first;
    static_assert(CheckMove<getRow, firstInstance+(GetAtIndex<R,getRow>::value::length), A, getRow::head::type>::value,
                      "You cannot move RIGHT, there is a car!");
    typedef typename SetAtIndex<C, typename ManyMoves<getRow, firstInstance, A,
                              GetAtIndex<R, getRow>::value::length, RIGHT>::list, aBoard2>::list newBoard1;
    typedef GameBoard<typename Transpose<newBoard1>::matrix> board;
};



#endif //OOP5_MOVEVEHICLE_H
