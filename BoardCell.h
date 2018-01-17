#ifndef OOP5_BOARDCELL_H
#define OOP5_BOARDCELL_H

#include "CellType.h"
#include "Direction.h"

template<CellType T, Direction D, int N>
struct BoardCell{
    constexpr static CellType type = T;
    constexpr static Direction direction = D;
    constexpr static int length = N;
};

#endif //OOP5_BOARDCELL_H
