#ifndef OOP5_MOVEVEHICLE_H
#define OOP5_MOVEVEHICLE_H

template<typename T, typename D, int N>
struct Move<T, D, N>{
    static_assert();
    typedef D direction;
    constexpr static int amount = N;
};


#endif //OOP5_MOVEVEHICLE_H
