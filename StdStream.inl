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
	a_os << "std::pair: {" << a_value.first  << "," << a_value.second << "}";	/// Delimiter ???

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
	stdstream::Print print("std::vector", ",", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::list", ",", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::set", ",", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::multiset", ",", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::deque", ",", a_os);
	print.container(a_value);

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

    stdstream::Print print("std::queue", ",", a_os);
    print.range(it_begin, it_end);

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

    stdstream::Print print("std::priority_queue", ",", a_os);
    print.range(it_begin, it_end);

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

    stdstream::Print print("std::stack", ",", a_os);
    print.range(it_begin, it_end);

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
	stdstream::Print print("std::map", "\n", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::multimap", "\n", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::array", ",", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::forward_list", ",", a_os);
	print.range(a_value.cbegin(), a_value.cend());

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
	stdstream::Print print("std::unordered_map", "\n", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::unordered_multimap", "\n", a_os);
	print.container(a_value);

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
	stdstream::Print print("std::unordered_set", ",", a_os);
	print.range(a_value.cbegin(), a_value.cend());

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
	stdstream::Print print("std::unordered_multiset", ",", a_os);
	print.range(a_value.cbegin(), a_value.cend());

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
	const std::string &a_contName,	///< contatiner name
	const std::string &a_delimiter,	///< items delimiter
	std::ostream      &out_os		///< [in,out] std::stream
) :
	_contName {a_contName},
	_delimiter{a_delimiter},
	_os       {out_os}
{
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::title(
    IteratorT a_first, ///< first iterator
    IteratorT a_last   ///< last iterator
)
{
	const std::size_t valueSize = std::distance(a_first, a_last);
	_os << _contName << " (size=" << valueSize << "): ";
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::range(
    IteratorT a_first, ///< first iterator
    IteratorT a_last   ///< last iterator
)
{
	// titile
	title(a_first, a_last);

	// body
    if (a_first == a_last) {
        _os << "{}";
        return;
    }

    _os << "{";
	_os << *a_first;

    for (++ a_first; a_first != a_last; ++ a_first) {
        _os << _delimiter;
        _os << *a_first;
    }

    _os << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename ContT>
inline void
Print::container(
    const ContT &a_value ///< container
)
{
	range(a_value.cbegin(), a_value.cend());
}
//-------------------------------------------------------------------------------------------------

} // ns stdstream
