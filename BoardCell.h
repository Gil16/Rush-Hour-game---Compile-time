#ifndef OOP5_BOARDCELL_H
#define OOP5_BOARDCELL_H

#include "CellType.h"
#include "Direction.h"

template<CellType T, Direction D, int N>
struct BoardCell<T, D, N>{
    typedef typename T type;
    typedef typename D direction;
    typedef N length;
};

#endif //OOP5_BOARDCELL_H
