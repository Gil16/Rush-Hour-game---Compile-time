#ifndef OOP5_GAMEBOARD_H
#define OOP5_GAMEBOARD_H

#include "List.h"

template<List<T, TT...> L,typename T, typename... TT>
struct GameBoard<List<T, TT...> >{
    constexpr typedef List board = L;
    constexpr static int width = sizeof(T);
    constexpr static int length = sizeof(TT...) + 1;
};

#endif //OOP5_GAMEBOARD_H
