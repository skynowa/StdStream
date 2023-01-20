/**
 * \file  StdStream.inl
 * \brief std::ostream printers
 */


//-------------------------------------------------------------------------------------------------
#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
    #include <cxxabi.h>
#endif

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
	const std::size_t valueSize = sizeof...(ArgsT);
	/// a_os << "std::tuple" << " (size=" << valueSize << "): ";
	a_os << stdstream::Print::typeNameDemangle(a_value) << " (size=" << valueSize << "): ";

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
Print::range(
    IteratorT a_first, ///< first iterator
    IteratorT a_last   ///< last iterator
)
{
	// titile
	_title(a_first, a_last);

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
    const ContT &a_cont ///< container
)
{
	range(a_cont.cbegin(), a_cont.cend());
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline void
Print::container(
	const std::pair<T1, T2> &a_cont ///< container
)
{
	// titile
	_os << _contName << ": ";

	// body
	_os << "{" << a_cont.first  << _delimiter << a_cont.second << "}";
}
//-------------------------------------------------------------------------------------------------
template<typename IteratorT>
inline void
Print::_title(
    IteratorT a_first, ///< first iterator
    IteratorT a_last   ///< last iterator
)
{
	const auto valueSize = std::distance(a_first, a_last);
	_os << _contName << " (size=" << valueSize << "): ";
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::string
Print::typeNameDemangle(
	const T &a_cont ///< container
)
{
	const char * const typeName = typeid( decltype(a_cont) ).name();

	std::string demangledName;
	{
	#if defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__)
		char        *buff   {};
		std::size_t *length {};
		int          status {- 1};

		char *pszRv = abi::__cxa_demangle(typeName, buff, length, &status);
		demangledName = (pszRv == nullptr) ? "<unknown>" : pszRv;

		std::free(pszRv);
		pszRv = nullptr;
	#else
		demangledName = (typeName == nullptr) ? "<unknown>" : typeName;
	#endif
	}

	std::string demangledNameCustom;

	// Template's info - remove (pair<int, int> -> pair)
	{
		const auto posBegin = demangledName.find("<");
		const auto posEnd   = demangledName.rfind(">");
		// std::cout << STD_TRACE_VAR2(posBegin, posEnd) << std::endl;

		if (posBegin != std::string::npos &&
			posEnd   != std::string::npos)
		{
			demangledNameCustom += demangledName.substr(0, posBegin);
			demangledNameCustom += demangledName.substr(posEnd + 1);
		}
	}

	// "__cxx11" - remove (std::__cxx11::list -> std::list)
	{
		const std::string cxxStr = "__cxx11::";

		const auto pos = demangledNameCustom.find(cxxStr);
		if (pos != std::string::npos) {
			demangledNameCustom.erase(pos, cxxStr.size());
		}
	}

    return demangledNameCustom;
}
//-------------------------------------------------------------------------------------------------

} // ns stdstream
