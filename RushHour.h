#ifndef OOP5_RUSHHOUR_H
#define OOP5_RUSHHOUR_H

#include "MoveVehicle.h"

template<GameBoard T>
struct CheckWin<T>{
    typedef GetCarRowNumber<T::board, X, 0, T::width, false>::value row;
    typedef GetAtIndex<row, T::board>::value redCarRow;
    typedef FindFirstInstanceOfACar<redCarRow, redCarRow::head::type, X, 0>::first firstInstance;
    typedef GetAtIndex<firstInstance, redCarRow>::value::length redCarSize;
    typedef CheckMove<redCarRow, firstInstance + redCarSize, T::board::width - (firstInstance + redCarSize), EMPTY>::value result;
};


template<GameBoard T, typename L, typename... LL>
struct CheckSolution<T, List<L, LL...> >{
    typedef GetCarRowNumber<T::board, L::type, 0, T::board::width, false>::value aRow;
    typedef FindFirstInstanceOfACar<GetAtIndex<aRow, T::board>::value, GetAtIndex<aRow, T::board>::value::head::type, L::type, 0>::first aCol;
    typedef typename CheckSolution<MoveVehicle<T, aRow, aCol, L::direction, L::amount> , List<LL...> >::result result;
};

template<GameBoard T, typename L, typename... LL>
struct CheckSolution<T, List<> >{
    typedef typename CheckWin<T>::result result;
};


// The List<T> here is the GameBoard -> I'm lazy to change it.
template<typename T, CellType CARTYPE, int LENGTH, int WIDTH, bool B>
struct GetCarRowNumber<List<T>, CARTYPE, LENGTH, WIDTH, B>{
    typedef typename GetCarRowNumber<List<T>::next, CARTYPE, LENGTH+1, IsCarHere<List<T>::head, CARTYPE, WIDTH,
                                                    List<T>::head::head::type>::value >::value value;
};

template<typename T, CellType CARTYPE, int LENGTH, int WIDTH>
struct GetCarRowNumber<List<T>, CARTYPE, LENGTH, WIDTH, true>{
    static int value = LENGTH-1;
};


template<typename T, CellType CARTYPE, int WIDTH, CellType TYPE>
struct IsCarHere<List<T>, CARTYPE, WIDTH, TYPE>{
    typedef typename IsCarHere<List<T>::next, WIDTH-1, List<T>::next::head::type >::value value;
};

template<typename T, CellType CARTYPE, int WIDTH>
struct IsCarHere<List<T>, CARTYPE, WIDTH, CARTYPE>{
    typedef typename bool value = true;
};

template<typename T, CellType CARTYPE, CellType TYPE>
struct IsCarHere<List<T>, CARTYPE, 1, TYPE>{
    typedef typename bool value = false;
};


#endif //OOP5_RUSHHOUR_H
