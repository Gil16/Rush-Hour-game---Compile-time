#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

#include "CellType.h"

template<CellType T, typename D, int N> // (**) not sure if CellType should be written here, but it works!
struct Move<T, D, N>{
    static_assert(T != EMPTY, "The Car type you enter was EMPTY, and it's not allowed!");
    typedef CellType type = T;  // same as the first note (**)
    typedef D direction;
    constexpr static int amount = N;
};


template<>
struct MoveVehicle<>{
    
};

#endif //OOP5_MOVEVEHICLE_H
