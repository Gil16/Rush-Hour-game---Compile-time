#ifndef OOP5_GAMEBOARD_H
#define OOP5_GAMEBOARD_H

/////////////  can i split it like this? i'm not sure..
template<typename T>
struct GameBoard<T>{
    typedef T board;
};

template<typename T, typename... TT>
struct GameBoard<T, TT...>{
    constexpr static int width = sizeof(T);
    constexpr static int length = sizeof(TT...) + 1;
};


#endif //OOP5_GAMEBOARD_H
