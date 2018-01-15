#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"

template<CellType T, Direction D, int N>
struct Move<T, D, N>{
    static_assert(T != EMPTY, "The Car type you enter was EMPTY, and it's not allowed!");
    constexpr typedef CellType type = T;
    constexpr typedef Direction direction = D;
    constexpr static int amount = N;
};


template<GameBoard GB, int R, int C, Direction D, int A>
struct MoveVehicle<GB, R, C, D, A>{
    constexpr typedef GameBoard board = GB;

};

#endif //OOP5_MOVEVEHICLE_H
