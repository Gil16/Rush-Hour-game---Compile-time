#ifndef OOP5_UTILITIES_H
#define OOP5_UTILITIES_H


template<typename T, typename R>
struct Conditional<true, T, R>{
    typedef T value;
};

template<typename T, typename R>
struct Conditional<false, T, R>{
    typedef R value;
};


template<int X,int Y>
struct ConditionalInteger<true, X, Y>{
    constexpr static int value = X;
};

template<int X,int Y>
struct ConditionalInteger<false, X, Y>{
    constexpr static int value = Y;
};



#endif //OOP5_UTILITIES_H
