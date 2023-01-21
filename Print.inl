/**
 * \file  Print.inl
 * \brief std::ostream printers
 */


#if defined(__GNUC__) || \
	defined(__MINGW32__) || defined(__MINGW64__) || \
	defined(__clang__)

    #include <cxxabi.h>
#endif

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
	// title
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
	// title
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
inline std::string
Print::typeNameDemangle(
	const T &a_cont ///< container
)
{
	const char * const typeName = typeid( decltype(a_cont) ).name();

	std::string demangledName;
	{
	#if defined(__GNUC__) || \
		defined(__MINGW32__) || defined(__MINGW64__) || \
		defined(__clang__)

		char        *buff   {};
		std::size_t *length {};
		int          status {- 1};

		char *pszRv = abi::__cxa_demangle(typeName, buff, length, &status);
		demangledName = (pszRv == nullptr) ? "<unknown>" : pszRv;

		std::free(pszRv);
		pszRv = nullptr;
	#elif defined(_MSC_VER)
		demangledName = (typeName == nullptr) ? "<unknown>" : typeName;
	#else
		demangledName = (typeName == nullptr) ? "<unknown>" : typeName;
	#endif
	}

	std::string demangledNameCustom;

	// Template's huge info - remove (pair<int, int> -> pair)
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
