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
	stdstream::printContainer("std::vector", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::list", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::set", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::multiset", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::deque", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::queue", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::priority_queue", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::stack", a_os, a_value.begin(), a_value.end());

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream           &a_os,
	const std::map<T1, T2> &a_value
)
{
	stdstream::printMap("std::map", a_os, a_value.begin(), a_value.end());

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream                &a_os,
	const std::multimap<T1, T2> &a_value
)
{
	stdstream::printMap("std::multimap", a_os, a_value.begin(), a_value.end());

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
	stdstream::printMap("std::map", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::array", a_os, a_value.begin(), a_value.end());

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
	a_os << "std::forward_list (" << a_value.size() << " elements)";
	stdstream::printContainer(a_os, "", a_value.begin(), a_value.end());

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
	stdstream::printMap("std::unordered_map", a_os, a_value.begin(), a_value.end());

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
	stdstream::printRangeMap("std::unordered_multimap", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::unordered_set", a_os, a_value.begin(), a_value.end());

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
	stdstream::printContainer("std::unordered_multiset", a_os, a_value.begin(), a_value.end());

	return a_os;
}
//--------------------------------------------------------------------------------------------------
template<typename Tuple, std::size_t N>
struct TuplePrinter
{
	static void
	print(std::ostream &a_os, const Tuple &a_t)
	{
		TuplePrinter<Tuple, N - 1>::print(a_os, a_t);
		a_os << ", " << std::get<N - 1>(a_t);
	}
};

template<typename Tuple>
struct TuplePrinter<Tuple, 1>
{
	static void
	print(std::ostream &a_os, const Tuple &a_t)
	{
		a_os << std::get<0>(a_t);
	}
};

template<typename... Args>
inline std::ostream &
operator << (
	std::ostream              &a_os,
	const std::tuple<Args...> &a_value
)
{
#if 0
	a_os << "std::tuple (" << std::tuple_size<decltype(a_value)>::value << " elements)";

	if ( a_value.empty() ) {
		return a_os;
	}
#else
	a_os << "std::tuple";
#endif

	a_os << ":" << std::endl;

	a_os << "{";
	TuplePrinter<decltype(a_value), sizeof...(Args)>::print(a_os, a_value);
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
printRange(
	std::ostream      &a_os, 		///< [in,out] std::stream
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	// titile
	if ( !a_contName.empty() ) {
		const std::size_t valueSize = std::distance(a_first, a_last);
		a_os << a_contName << " (" << valueSize << " elements)";
	}

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
    const ContT       &a_cont		///< container
)
{
	stdstream::printRange(a_os, a_contName,	a_cont);
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
	// titile
	if ( !a_contName.empty() ) {
		const std::size_t valueSize = std::distance(a_first, a_last);
		a_os << a_contName << " (" << valueSize << " elements)";
	}

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
    const MapT        &a_cont		///< container
)
{
	stdstream::printRangeMap(a_os, a_contName,	a_cont);
}
//-------------------------------------------------------------------------------------------------

}
