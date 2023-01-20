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
	a_os << "std::pair: {" << a_value.first  << "," << a_value.second << "}";

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
	stdstream::Print print(a_os);
	print.container("std::vector", a_value);

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
	stdstream::Print print(a_os);
	print.container("std::list", a_value);

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
	stdstream::Print print(a_os);
	print.container("std::set", a_value);

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
	stdstream::Print print(a_os);
	print.container("std::multiset", a_value);

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
	stdstream::Print print(a_os);
	print.container("std::deque", a_value);

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

    stdstream::Print print(a_os);
    print.range("std::queue", it_begin, it_end);

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

    stdstream::Print print(a_os);
    print.range("std::priority_queue", it_begin, it_end);

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

    stdstream::Print print(a_os);
    print.range("std::stack", it_begin, it_end);

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
	stdstream::Print print(a_os);
	print.map("std::map", a_value);

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
	stdstream::Print print(a_os);
	print.map("std::multimap", a_value);

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
	stdstream::Print print(a_os);
	print.container("std::array", a_value);

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
	stdstream::Print print(a_os);
	print.range("std::forward_list", a_value.cbegin(), a_value.cend());

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
	stdstream::Print print(a_os);
	print.map("std::unordered_map", a_value);

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
	stdstream::Print print(a_os);
	print.map("std::unordered_multimap", a_value);

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
	stdstream::Print print(a_os);
	print.range("std::unordered_set", a_value.cbegin(), a_value.cend());

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
	stdstream::Print print(a_os);
	print.range("std::unordered_multiset", a_value.cbegin(), a_value.cend());

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
		a_os << "," << std::get<N - 1>(a_t);
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
inline
Print::Print(
	std::ostream &out_os ///< [in,out] std::stream
) :
	_os{out_os}
{
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::title(
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	const std::size_t valueSize = std::distance(a_first, a_last);
	_os << a_contName << " (size=" << valueSize << "): ";
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::range(
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	// titile
	title(a_contName, a_first, a_last);

	// body
    if (a_first == a_last) {
        _os << "{}";
        return;
    }

    _os << "{";
	_os << *a_first;

    for (++ a_first; a_first != a_last; ++ a_first) {
        _os << ",";
        _os << *a_first;
    }

    _os << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename ContT>
inline void
Print::container(
	const std::string &a_contName,	///< container name
    const ContT       &a_value		///< container
)
{
	range(a_contName, a_value.cbegin(), a_value.cend());
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::rangeMap(
	const std::string &a_contName,	///< container name
    IteratorT          a_first,		///< first iterator
    IteratorT          a_last		///< last iterator
)
{
	// title
	title(a_contName, a_first, a_last);

	// body
    if (a_first == a_last) {
        _os << "{}";
        return;
    }

    _os << "{";
	_os << *a_first;

    for (++ a_first; a_first != a_last; ++ a_first) {
        _os << "\n";
        _os << *a_first;
    }

    _os << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename MapT>
inline void
Print::map(
	const std::string &a_contName,	///< container name
    const MapT        &a_value		///< container
)
{
	rangeMap(a_contName, a_value.cbegin(), a_value.cend());
}
//-------------------------------------------------------------------------------------------------

}
