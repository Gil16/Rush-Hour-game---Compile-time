#ifndef OOP5_GAMEBOARD_H
#define OOP5_GAMEBOARD_H

#include "List.h"


template<typename T>
struct GameBoard{
    typedef T board;
    constexpr static int width = sizeof(board::head);
    constexpr static int length = sizeof(board);
};

#endif //OOP5_GAMEBOARD_H
