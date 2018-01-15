#ifndef OOP5_BOARDCELL_H
#define OOP5_BOARDCELL_H


template<typename T, typename D, int n>
struct BoardCell<T, D, n>{
    typedef T type;
    typedef D direction;
    constexpr static int length = n;
};

#endif //OOP5_BOARDCELL_H
