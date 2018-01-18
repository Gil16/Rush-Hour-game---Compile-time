#ifndef OOP5_GAMEBOARD_H
#define OOP5_GAMEBOARD_H

#include "List.h"


template<typename T>
struct GameBoard{
    typedef T board;
    constexpr static int width = board::head::size;
    constexpr static int length = board::size;
};

#endif //OOP5_GAMEBOARD_H
