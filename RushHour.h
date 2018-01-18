#ifndef OOP5_RUSHHOUR_H
#define OOP5_RUSHHOUR_H

#include "MoveVehicle.h"


template<typename T, CellType CARTYPE, int WIDTH, CellType TYPE>
struct IsCarHere{
    constexpr static bool value = IsCarHere<typename T::next, CARTYPE, WIDTH-1, T::next::head::type >::value;
};

template<typename T, CellType CARTYPE, int WIDTH>
struct IsCarHere<T, CARTYPE, WIDTH, CARTYPE>{
    constexpr static bool value = true;
};

template<typename T, CellType CARTYPE, CellType TYPE>
struct IsCarHere<T, CARTYPE, 1, TYPE>{
    constexpr static bool value = false;
};

template<typename T, CellType CARTYPE>
struct IsCarHere<T, CARTYPE, 1, CARTYPE>{
    constexpr static bool value = true;
};


// The List<T> here is the GameBoard -> I'm lazy to change it.
template<typename T, CellType CARTYPE, int LENGTH, int WIDTH, bool B>
struct GetCarRowNumber{
    constexpr static int value = GetCarRowNumber<typename T::next, CARTYPE, LENGTH+1, WIDTH, IsCarHere<typename T::head, CARTYPE, WIDTH,
            T::head::head::type>::value>::value;
};

template<typename T, CellType CARTYPE, int LENGTH, int WIDTH>
struct GetCarRowNumber<T, CARTYPE, LENGTH, WIDTH, true>{
    constexpr static int value = LENGTH-1;
};


template<typename T>
struct CheckWin{
    constexpr static int row = GetCarRowNumber<typename T::board, X, 0, T::width, false>::value ;
    typedef typename GetAtIndex<row, typename T::board>::value redCarRow;
    constexpr static int firstInstance = FindFirstInstanceOfACar<redCarRow, redCarRow::head::type, X, 0>::first;
    constexpr static int redCarSize = GetAtIndex<firstInstance, redCarRow>::value::length;
    constexpr static bool result = CheckMove<redCarRow, firstInstance + redCarSize, T::width - (firstInstance + redCarSize), EMPTY>::value;
};


template<typename T, typename MOVES>
struct CheckSolution{
    //static_assert((T::width == 6),"oops");
    constexpr static int aRow = GetCarRowNumber<typename T::board, MOVES::head::type, 0, T::width, false>::value;
    constexpr static int aCol = FindFirstInstanceOfACar<
            typename GetAtIndex<aRow, typename T::board>::value, GetAtIndex<aRow, typename T::board>::value::head::type
                             , MOVES::head::type, 0>::first;
    constexpr static bool result = CheckSolution<typename MoveVehicle<T, aRow, aCol,
                 MOVES::head::direction, MOVES::head::amount>::board , typename MOVES::next >::result;
};

template<typename T>
struct CheckSolution<T, List<> >{
    constexpr static bool result = CheckWin<T>::result;
};




#endif //OOP5_RUSHHOUR_H
