#ifndef OOP5_LIST_H
#define OOP5_LIST_H


template <typename T, typename... TT>
struct List<T, TT...>{
public:
    typedef typename T head;
    typedef typename List<TT...> next;
    constexpr static int size = sizeof...(TT) + 1;      // can we do it like this?
};
/*      needed?
template <>
struct List<>{
public:
    constexpr static int size = 0;
};
*/

template <typename T, typename... TT, List<TT...> L>
struct PrependList<T, L>{
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


template<int N, typename T, typename ...L>
struct SetAtIndex{};

template<int N, typename T, typename L, typename... LL>
struct SetAtIndex<N, T, List<L, LL...> >{
    typedef typename PrependList<L,SetAtIndex<N-1, T, List<LL...> > >::list list;
};

template<int N, typename T, typename L, typename... LL>
struct SetAtIndex<0, T, List<L, LL...>>{
    List<T, LL...> list;
};

#endif //OOP5_LIST_H
