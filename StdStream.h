/**
 * \file  StdStream.h
 * \brief std::ostream printers
 */


#pragma once

//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <queue>
#include <set>
#include <stack>
#include <array>
#include <forward_list>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
//-------------------------------------------------------------------------------------------------
///@name Trace variables (variable with value)
///@{
#define STD_TRACE_VAR(v1) \
	#v1 ": " << (v1)
#define STD_TRACE_VAR2(v1, v2) \
	STD_TRACE_VAR(v1) << ", " << STD_TRACE_VAR(v2)
#define STD_TRACE_VAR3(v1, v2, v3) \
	STD_TRACE_VAR2(v1, v2) << ", " << STD_TRACE_VAR(v3)
#define STD_TRACE_VAR4(v1, v2, v3, v4) \
	STD_TRACE_VAR3(v1, v2, v3) << ", " << STD_TRACE_VAR(v4)
#define STD_TRACE_VAR5(v1, v2, v3, v4, v5) \
	STD_TRACE_VAR4(v1, v2, v3, v4) << ", " << STD_TRACE_VAR(v5)
#define STD_TRACE_VAR6(v1, v2, v3, v4, v5, v6) \
	STD_TRACE_VAR5(v1, v2, v3, v4, v5) << ", " << STD_TRACE_VAR(v6)
#define STD_TRACE_VAR7(v1, v2, v3, v4, v5, v6, v7) \
	STD_TRACE_VAR6(v1, v2, v3, v4, v5, v6) << ", " << STD_TRACE_VAR(v7)
#define STD_TRACE_VAR8(v1, v2, v3, v4, v5, v6, v7, v8) \
	STD_TRACE_VAR7(v1, v2, v3, v4, v5, v6, v7) << ", " << STD_TRACE_VAR(v8)
#define STD_TRACE_VAR9(v1, v2, v3, v4, v5, v6, v7, v8, v9) \
	STD_TRACE_VAR8(v1, v2, v3, v4, v5, v6, v7, v8) << ", " << STD_TRACE_VAR(v9)
#define STD_TRACE_VAR10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) \
	STD_TRACE_VAR9(v1, v2, v3, v4, v5, v6, v7, v8, v9) << ", " << STD_TRACE_VAR(v10)
#define STD_TRACE_VAR11(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) \
	STD_TRACE_VAR10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) << ", " << STD_TRACE_VAR(v11)

#define STD_PRINT_VAR(v) \
	#v ": [" << (v) << "]"
	///< trace variable with delimiters ("[var]")
#define STD_UNKNOWN_VAR(v) \
	"Unknown " << STD_TRACE_VAR(v)
#define STD_INVALID_VAR(v) \
	"Invalid " << STD_TRACE_VAR(v)
#define STD_TRACE_PTR(p) \
	#p ": " << "{" << (p) << ", " << ((p) ? *(p) : 0) << "}"
#define STD_TITLE_VAR(v) \
	"::::: " << (v) << " :::::"
	///< trace variable as titlebar
///@}
//-------------------------------------------------------------------------------------------------
#define STD_TRACE_POINT \
    { \
        std::cout \
            << "\t::: " \
            << " in "      << __FILE__ \
            << ":"         << __LINE__ \
            << ", error: " << std::strerror(errno) \
            << " :::"      << std::endl; \
    }
    ///< trace point
#define STD_TRACE_FUNC \
    { \
        std::cout << "\t::: " << __FUNCTION__ << " :::" << std::endl; \
    }
    ///< trace function
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   overload operators <<
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
template<class T>
auto operator << (std::ostream &os, const T &value) -> decltype(value.print(os), os);
	///< Print any object which has a member:
	///< void T::print(std::ostream&) const;
template<typename T1, typename T2>
std::ostream & operator << (std::ostream &os, const std::pair<T1, T2> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::vector<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::list<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::set<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::multiset<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::deque<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::queue<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::priority_queue<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::stack<T> &value);

template<typename T1, typename T2, class CompareT>
std::ostream & operator << (std::ostream &os, const std::map<T1, T2, CompareT> &value);

template<typename T1, typename T2, class CompareT>
std::ostream & operator << (std::ostream &os, const std::multimap<T1, T2> &value);

template<typename T, std::size_t N>
std::ostream & operator << (std::ostream &os, const std::array<T, N> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::forward_list<T> &value);

template<typename T1, typename T2>
std::ostream & operator << (std::ostream &os, const std::unordered_map<T1, T2> &value);

template<typename T1, typename T2>
std::ostream & operator << (std::ostream &os, const std::unordered_multimap<T1, T2> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::unordered_set<T> &value);

template<typename T>
std::ostream & operator << (std::ostream &os, const std::unordered_multiset<T> &value);

template<typename... Args>
std::ostream & operator << (std::ostream &os, const std::tuple<Args...> &value);
//-------------------------------------------------------------------------------------------------
namespace stdstream
{

//-------------------------------------------------------------------------------------------------
class Print final
	///
{
public:
///\name ctors, dtor
///\{
	Print(std::ostream &os);
	~Print() = default;

	Print() = delete;
	Print(const Print &) = delete;
	Print(Print &&) = delete;
	Print & operator = (const Print &) = delete;
	Print & operator = (Print &&) = delete;
///\}

	template<typename IteratorT>
	void title(const std::string &contName, IteratorT first, IteratorT last);

	template<typename IteratorT>
	void range(const std::string &contName, IteratorT first, IteratorT last);
	template<typename ContT>
	void container(const std::string &contName, const ContT &cont);

	template<typename IteratorT>
	void rangeMap(const std::string &contName, IteratorT first, IteratorT last);
	template<typename MapT>
	void map(const std::string &contName, const MapT &cont);

private:
	std::ostream &_os;
};
//-------------------------------------------------------------------------------------------------


}
//-------------------------------------------------------------------------------------------------
#include "StdStream.inl"
