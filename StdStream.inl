/**
 * \file  StdStream.inl
 * \brief std::ostream printers
 */


//-------------------------------------------------------------------------------------------------
template<class T>
auto
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
	a_os << "std::vector (" << a_value.size() << " elements)";

	if ( a_value.empty() )  {
		return a_os;
	}

	a_os << ":" << std::endl;

	for (auto it = a_value.begin(); it != a_value.end(); ++ it) {
		a_os << "    [" << std::distance(a_value.begin(), it) << "]: " << *it;

		if (it + 1 != a_value.end()) {
			 a_os << std::endl;
		}
	}

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
	a_os << "std::list (" << a_value.size() << " elements)";

	if ( a_value.empty() ) {
		return a_os;
	}

	a_os << ":" << std::endl;

	for (auto it = a_value.begin(); it != a_value.end(); ++ it) {
		a_os << "    [" << std::distance(a_value.begin(), it) << "]: " << *it;

		if (++ it != a_value.end()) {
			 a_os << std::endl;
		}

		-- it;
	}

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::set<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::multiset<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::deque<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::queue<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::priority_queue<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
std::ostream & operator << (
	const std::stack<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
inline std::ostream &
operator << (
	std::ostream           &a_os,
	const std::map<T1, T2> &a_value
)
{
	a_os << "std::map (" << a_value.size() << " elements)";

	if ( a_value.empty() ) {
		return a_os;
	}

	a_os << ":" << std::endl;

	for (auto it = a_value.begin(); it != a_value.end(); ++ it) {
		a_os << "    {" << it->first  << ", " << it->second << "}";

		if (++ it != a_value.end()) {
			 a_os << std::endl;
		}

		-- it;
	}

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
	a_os << std::endl;
	a_os << "std::multimap (" << a_value.size() << " elements):" << std::endl;

	typename std::multimap<T1, T2>::const_iterator it;
	for (it = a_value.begin(); it != a_value.end(); ++ it) {
		a_os << "    {" << it->first  << ", " << it->second << "}";

		if (++ it != a_value.end()) {
			 a_os << std::endl;
		}

		-- it;
	}

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
	a_os << "std::map (" << a_value.size() << " elements)";

	if ( a_value.empty() ) {
		return a_os;
	}

	a_os << ":" << std::endl;

	for (auto it = a_value.begin(); it != a_value.end(); ++ it) {
		a_os << "    {" << it->first  << ", " << it->second << "}";

		if (++ it != a_value.end()) {
			 a_os << std::endl;
		}

		-- it;
	}

	return a_os;
}
//-------------------------------------------------------------------------------------------------
template<typename T, std::size_t N>
OStream & operator << (
	const std::array<T, N> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
OStream & operator << (
	const std::forward_list<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
OStream & operator << (
	const std::unordered_map<T1, T2> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T1, typename T2>
OStream & operator << (
	const std::unordered_multimap<T1, T2> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
OStream & operator << (
	const std::unordered_set<T> &a_value
)
{
	// TODO: impl
}
//-------------------------------------------------------------------------------------------------
template<typename T>
OStream & operator << (
	const std::unordered_multiset<T> &a_value
)
{
	// TODO: impl
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
