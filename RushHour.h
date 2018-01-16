#ifndef OOP5_RUSHHOUR_H
#define OOP5_RUSHHOUR_H

#include "MoveVehicle.h"

template<GameBoard T>
struct CheckWin<T>{

};

// tomorrow
template<typename T, int LENGTH, int WIDTH, bool B>
struct GetRedRowNumber<List<T>, LENGTH, WIDTH, B>{
    typedef typename GetRedRowNumber<List<T>::next, LENGTH-1, IsRedHere<List<T>::head, WIDTH, List<T>::head::head::type> >::list list ;
};

template<typename T, int LENGTH, int WIDTH>
struct GetRedRowNumber<List<T>, LENGTH, WIDTH, true>{
    typedef typename List<T>::head list ;
};

template<typename T, int LENGTH, int WIDTH, bool B>
struct GetRedRowNumber<List<T>, 1, WIDTH, B>{
    typedef typename List<T>::head list;
};


template<typename T, int WIDTH, CellType TYPE>
struct IsRedHere<List<T>, WIDTH, TYPE>{
    typedef typename IsRedHere<List<T>::next, WIDTH-1, List<T>::next::head::type >::value value;
};

template<typename T, int WIDTH>
struct IsRedHere<List<T>, WIDTH, X>{
    typedef typename bool value = true;
};

template<typename T, CellType TYPE>
struct IsRedHere<List<T>, 1, TYPE>{
    typedef typename bool value = false;
};


#endif //OOP5_RUSHHOUR_H
