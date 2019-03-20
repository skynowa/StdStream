/**
 * \file  StdStream.inl
 * \brief std::ostream printers
 */


//-------------------------------------------------------------------------------------------------
template<class T>
inline auto
operator << (
	std::ostream &a_os,
	const T      &a_value
) -> decltype(a_value.print(a_os), a_os)
{
	a_value.print(a_os);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream            &a_os,
	const std::pair<T1, T2> &a_value
)
{
	a_os << "std::pair: {" << a_value.first  << ", " << a_value.second << "}";

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream         &a_os,
	const std::vector<T> &a_value
)
{
	stdstream::printContainer(a_os, "std::vector", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream       &a_os,
	const std::list<T> &a_value
)
{
	stdstream::printContainer(a_os, "std::list", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream      &a_os,
	const std::set<T> &a_value
)
{
	stdstream::printContainer(a_os, "std::set", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream           &a_os,
	const std::multiset<T> &a_value
)
{
	stdstream::printContainer(a_os, "std::multiset", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream        &a_os,
	const std::deque<T> &a_value
)
{
	stdstream::printContainer(a_os, "std::deque", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream        &a_os,
	const std::queue<T> &a_value
)
{
	using const_iterator = const T *;

    const_iterator it_begin = &a_value.front();
    const_iterator it_end   = &a_value.front() + a_value.size();

	stdstream::printRange(a_os, "std::queue", it_begin, it_end);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream                 &a_os,
	const std::priority_queue<T> &a_value
)
{
    using const_iterator = const T *;

    const_iterator it_begin = &a_value.top();
    const_iterator it_end   = &a_value.top() + a_value.size();

	stdstream::printRange(a_os, "std::priority_queue", it_begin, it_end);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream        &a_os,
	const std::stack<T> &a_value
)
{
	using const_iterator = const T *;

    const_iterator it_begin = &a_value.top() - a_value.size() + 1;
    const_iterator it_end   = &a_value.top() + 1;

	stdstream::printRange(a_os, "std::stack", it_begin, it_end);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2, class CompareT>
inline std::ostream &
operator << (
	std::ostream                     &a_os,
	const std::map<T1, T2, CompareT> &a_value
)
{
	stdstream::printMap(a_os, "std::map", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2, class CompareT>
inline std::ostream &
operator << (
	std::ostream                          &a_os,
	const std::multimap<T1, T2, CompareT> &a_value
)
{
	stdstream::printMap(a_os, "std::multimap", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
inline std::ostream &
operator << (
	std::ostream           &a_os,
	const std::array<T, N> &a_value
)
{
	stdstream::printContainer(a_os, "std::array", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream               &a_os,
	const std::forward_list<T> &a_value
)
{
	stdstream::printRange(a_os, "std::forward_list", a_value.begin(), a_value.end());

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream                     &a_os,
	const std::unordered_map<T1, T2> &a_value
)
{
	stdstream::printMap(a_os, "std::unordered_map", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream                          &a_os,
	const std::unordered_multimap<T1, T2> &a_value
)
{
	stdstream::printMap(a_os, "std::unordered_multimap", a_value);

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream                &a_os,
	const std::unordered_set<T> &a_value
)
{
	stdstream::printRange(a_os, "std::unordered_set", a_value.begin(), a_value.end());

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
inline std::ostream &
operator << (
	std::ostream                     &a_os,
	const std::unordered_multiset<T> &a_value
)
{
	stdstream::printRange(a_os, "std::unordered_multiset", a_value.begin(), a_value.end());

	return a_os;
}
//--------------------------------------------------------------------------------------------------
template<typename TupleT, std::size_t N>
struct TuplePrinter
{
	static void
	print(std::ostream &a_os, const TupleT &a_t)
	{
		TuplePrinter<TupleT, N - 1>::print(a_os, a_t);
		a_os << ", " << std::get<N - 1>(a_t);
	}
};

template<typename TupleT>
struct TuplePrinter<TupleT, 1>
{
	static void
	print(std::ostream &a_os, const TupleT &a_t)
	{
		a_os << std::get<0>(a_t);
	}
};

template<typename... ArgsT>
inline std::ostream &
operator << (
	std::ostream               &a_os,
	const std::tuple<ArgsT...> &a_value
)
{
	const std::size_t valueSize = sizeof...(ArgsT);
	a_os << "std::tuple" << " (size=" << valueSize << "): ";

	if (valueSize == 0) {
        a_os << "{}";
		return a_os;
	}

	a_os << "{";
	TuplePrinter<decltype(a_value), sizeof...(ArgsT)>::print(a_os, a_value);
	a_os << "}";

	return a_os;
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*	stdstream
*
**************************************************************************************************/

namespace stdstream
{

//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
printTitle(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	const std::size_t valueSize = std::distance(a_first, a_last);
	a_os << a_contName << " (size=" << valueSize << "): ";
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
printRange(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	// titile
	stdstream::printTitle(a_os, a_contName, a_first, a_last);

	// body
    if (a_first == a_last) {
        a_os << "{}";
        return;
    }

    a_os << "{";
	a_os << *a_first;

    for (++ a_first; a_first != a_last; ++ a_first) {
        a_os << ",";
        a_os << *a_first;
    }

    a_os << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename ContT>
inline void
printContainer(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    const ContT       &a_value		///< container
)
{
	stdstream::printRange(a_os, a_contName, a_value.begin(), a_value.end());
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
printRangeMap(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	// title
	stdstream::printTitle(a_os, a_contName, a_first, a_last);

	// body
    if (a_first == a_last) {
        a_os << "{}";
        return;
    }

    a_os << "{";
	a_os << *a_first;

    for (++ a_first; a_first != a_last; ++ a_first) {
        a_os << "\n";
        a_os << *a_first;
    }

    a_os << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename MapT>
inline void
printMap(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    const MapT        &a_value		///< container
)
{
	stdstream::printRangeMap(a_os, a_contName, a_value.begin(), a_value.end());
}
//-------------------------------------------------------------------------------------------------

}
