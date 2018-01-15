#ifndef OOP5_LIST_H
#define OOP5_LIST_H


template <typename T, typename... TT>
struct List<T, TT...>{
public:
    typedef T head;
    typedef List<TT...> next;
    constexpr static int size = sizeof...(TT) + 1;      // can we do it like this?
};
/*      needed?
template <>
struct List<>{
public:
    constexpr static int size = 0;
};
*/

// not complete, i think        ,  maybe an empty list case is needed??
template <typename T, typename... L>   // List as parameter?
struct PrependList<List<T>, L>{
public:
    typedef PrependList<List<T...>, typename PrependList<L>::list>::list list;      // no clue, is it ok?
};

////////////////////////    from the tutorials
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
//////////////////////////


template<int N, typename T, typename ...L>
struct SetAtIndex{};

template<int N, typename T, typename ...L>
struct SetAtIndex<N, T, List<L...> >{
    typedef typename SetAtIndex<>::list list;   // need to continue it somehow
};

#endif //OOP5_LIST_H
