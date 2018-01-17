#ifndef OOP5_LIST_H
#define OOP5_LIST_H

struct NIL{};

template <typename T, typename... TT>
struct List{
public:
    typedef T head;
    typedef List<TT...> next;
    constexpr static int size = sizeof...(TT) + 1;      // can we do it like this?
};

template <typename T>
struct List<T>{
public:
    typedef T head;
    typedef NIL next;
    constexpr static int size = 1;
};


template <typename T, typename... TT>
struct PrependList{};

template <typename T, typename... TT>
struct PrependList<T,  List<TT...>>{
public:
    typedef List<T,TT...> list;
};


template<int N, typename T>
struct GetAtIndex {};

template<int N, typename T, typename... L>
struct GetAtIndex<N, List<T, L... > > {
    typedef typename GetAtIndex<N-1, List<L...> >::value value;
};

template<typename T, typename... L>
struct GetAtIndex<0, List<T, L... > > {
    typedef T value;
};


template<int N, typename T, typename L, typename ...LL>
struct SetAtIndex{};

template<int N, typename T, typename L, typename... LL>
struct SetAtIndex<N, T, List<L, LL...> >{
    typedef typename PrependList<L,typename SetAtIndex<N-1, T, List<LL...>>::list>::list list;
};

template<typename T, typename L, typename... LL>
struct SetAtIndex<0, T, List<L, LL...>>{
    typedef List<T, LL...> list;
};

#endif //OOP5_LIST_H
