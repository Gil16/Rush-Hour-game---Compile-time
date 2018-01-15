#ifndef OOP5_UTILITIES_H
#define OOP5_UTILITIES_H


template<bool B, typename T, typename R>    // bool B  -> is needed?
struct Conditional<true, T, R>{
    typedef T value;       // what do i put here??   maybe nothing?
};

template<bool B, typename T, typename R>    // bool B  -> is needed?
struct Conditional<false, T, R>{
    typedef R value;      // what do i put here??   maybe nothing?
};


template<bool B, int X,int Y>   // bool B  -> is needed?
struct ConditionalInteger<true, X, Y>{
    static const int value = X;
};

template<bool B, int X,int Y>   // bool B  -> is needed?
struct ConditionalInteger<false, X, Y>{
    static const int value = Y;
};



#endif //OOP5_UTILITIES_H
