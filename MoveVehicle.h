#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

#include "CellType.h"
#include "BoardCell.h"
#include "Direction.h"
#include "GameBoard.h"
#include "List.h"
#include "TransposeList.h"


template<CellType T, Direction D, int N>
struct Move<T, D, N>{
    static_assert(T != EMPTY, "The Car type you enter was EMPTY, and it's not allowed!");
    constexpr CellType type = T;
    constexpr Direction direction = D;
    constexpr static int amount = N;
};


template<GameBoard GB, int R, int C, Direction D, int A>
struct MoveVehicle<GB, R, C, D, A>{
    constexpr typedef GameBoard board = GB;
    static_assert((R >= board::length) || (R < 0), "The given Row number is incorrect");
    static_assert((C >= board::width) || (C < 0), "The given Col number is incorrect");
    static_assert(GetAtIndex<C, GetAtIndex<R, board::board>::value >::value::type != EMPTY , "The given Cell is EMPTY");

    int temp = GetAtIndex<C, GetAtIndex<R, board::board>::value >::value::direction;
    static_assert((temp % 2) ? ((temp == D) || ((temp + 1) == D)) : ((temp == D) || ((temp - 1) == D)),
                                                                "The given direction is no the excpected");

    if((D == UP) || (D == DOWN)){
        board = Transpose<board>::matrix;
        int temp = R;
        R = C;
        C = temp;
    }
    typedef GetAtIndex<R, board::board>::value getRow;
    static int firstInstance = FindFirstInstanceOfACar<getRow, getRow::head::type, GetAtIndex<C,getRow>::value::type,0>;
    if((D == RIGHT) || (D == DOWN)){
        static_assert(CheckMove<getRow, firstInstance+(GetAtIndex<C,getRow>::value::length), A, getRow::head::type>,
                                            "You cannot move RIGHT, there is a car!");
    }
    if((D == LEFT) || (D == UP)){
        static_assert(CheckMove<getRow, firstInstance-A, A, getRow::head::type, "You cannot move LEFT, there is a car!");
    }



};


template<typename L, CellType CURRTYPE, CellType CARTYPE, int N>
struct FindFirstInstanceOfACar<List<L>, CURRTYPE, CARTYPE, N>{
    typedef typename List<L>::head Head;
    static int FindFirstInstanceOfACar<List<L>::next, Head::type , CARTYPE, N+1>::first first;
};

template<typename L , CellType T, int N>
struct FindFirstInstanceOfACar<List<L>, T, T, N>{
  //  typedef typename List<L>::head Head;
    static int first = N;
};


// Here we check if we can move the STEPS amount, only if all the STEPS are EMPTY.
// The structure is meant for 2 cases: 1) for moving right 2) for moving left
// 1) The LOCATION is the beginning of the car location, and then we will check the number of STEPS to it's new location.
// 2) The LOCATION is the end of the new location of the car, and then we will check the number of STEPS to the right.
template<typename T, int LOCATION, int STEPS, CellType TYPE>
struct CheckMove<List<T>, LOCATION, STEPS, TYPE>{
    typedef typename CheckMove< List<T>::next, LOCATION-1, STEPS, List<T>::next::head::type >::value value;
};

template<typename T, int STEPS>
struct CheckMove<List<T>, 0, STEPS, EMPTY>{
    typedef typename CheckMove<List<T>::next, 0, STEPS-1, List<T>::next::head::type>::value value;
};

template<typename T, int STEPS, CellType TYPE>
struct CheckMove<List<T>, 0, STEPS, TYPE>{
    typedef typename bool value = false;
};

template<typename T>
struct CheckMove<List<T>, 0, 1, EMPTY>{
    typedef typename bool value = true;
};

// LOCATION here is the first instance of the car on the LEFT
template<typename T, int LOCATION, int LENGTH, CellType D>
struct OneMove<List<T>, LOCATION, LENGTH, RIGHT>{
    typedef GetAtIndex<LOCATION, List<T>>::value CurrentCell;
    typedef typename SetAtIndex<LOCATION, BoardCell<EMPTY, UP, 0>, SetAtIndex<LOCATION+LENGTH, CurrentCell, List<T> > >;
};

// LOCATION here is the first instance of the car on the RIGHT
template<typename T, int LOCATION, int LENGTH, CellType D>
struct OneMove<List<T>, LOCATION, LENGTH, LEFT>{
    typedef GetAtIndex<LOCATION, List<T>>::value CurrentCell;
    typedef typename SetAtIndex<LOCATION-LENGTH, CurrentCell , SetAtIndex<LOCATION, BoardCell<EMPTY, UP, 0>, List<T> > >;
};


template<typename T, int LOCATION ,int N>
struct ManyMoves<List<T>, LOCATION, N >{

};

template<>
struct ManyMoves<>{

};

#endif //OOP5_MOVEVEHICLE_H
