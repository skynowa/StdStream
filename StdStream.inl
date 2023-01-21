/**
 * \file  StdStream.inl
 * \brief std::ostream printers
 */


#include "Print.h"

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
#if 0
	/// a_os << "std::pair: {" << a_value.first  << "," << a_value.second << "}";	/// Delimiter ???
	a_os
		<< stdstream::Print::typeNameDemangle(a_value) << ": "
		<< "{" << a_value.first  << "," << a_value.second << "}";	/// Delimiter ???
#else
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
	print.container(a_value);
#endif

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
	/// stdstream::Print print("std::vector", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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
	/// stdstream::Print print("std::list", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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
	/// stdstream::Print print("std::set", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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
	/// stdstream::Print print("std::multiset", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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
	/// stdstream::Print print("std::deque", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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

    const_iterator it_cbegin = &a_value.front();
    const_iterator it_cend   = &a_value.front() + a_value.size();

    /// stdstream::Print print("std::queue", ",", a_os);
    stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
    print.range(it_cbegin, it_cend);

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

    const_iterator it_cbegin = &a_value.top();
    const_iterator it_cend   = &a_value.top() + a_value.size();

    /// stdstream::Print print("std::priority_queue", ",", a_os);
    stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
    print.range(it_cbegin, it_cend);

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

    const_iterator it_cbegin = &a_value.top() - a_value.size() + 1;
    const_iterator it_cend   = &a_value.top() + 1;

    /// stdstream::Print print("std::stack", ",", a_os);
    stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
    print.range(it_cbegin, it_cend);

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
	/// stdstream::Print print("std::map", "\n", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), "\n", a_os);
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
	/// stdstream::Print print("std::multimap", "\n", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), "\n", a_os);
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
	/// stdstream::Print print("std::array", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
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
	/// stdstream::Print print("std::forward_list", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
	print.container(a_value);

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
	/// stdstream::Print print("std::unordered_map", "\n", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), "\n", a_os);
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
	/// stdstream::Print print("std::unordered_multimap", "\n", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), "\n", a_os);
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
	/// stdstream::Print print("std::unordered_set", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
	print.container(a_value);

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
	/// stdstream::Print print("std::unordered_multiset", ",", a_os);
	stdstream::Print print(stdstream::Print::typeNameDemangle(a_value), ",", a_os);
	print.container(a_value);

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
		a_os << "," << std::get<N - 1>(a_t);	/// Delimiter ???
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
	// title
	constexpr std::size_t valueSize = sizeof...(ArgsT);
	/// a_os << "std::tuple" << " (size=" << valueSize << "): ";
	a_os << stdstream::Print::typeNameDemangle(a_value) << " (size=" << valueSize << "): ";

	// body
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
