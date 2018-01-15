#ifndef OOP5_BOARDCELL_H
#define OOP5_BOARDCELL_H

#include "CellType.h"
#include "Direction.h"

template<CellType T, Direction D, int N>
struct BoardCell<T, D, N>{
    constexpr CellType type = T;
    constexpr Direction direction = D;
    constexpr static int length = N;
};

#endif //OOP5_BOARDCELL_H
