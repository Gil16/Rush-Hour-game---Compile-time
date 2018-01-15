#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

#include "CellType.h"
#include "Direction.h"
#include "GameBoard.h"
#include "List.h"

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
    static_assert(GetAtIndex<C, GetAtIndex<R, board::board>::value >::value , "");


};

#endif //OOP5_MOVEVEHICLE_H
