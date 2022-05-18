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
#define TRACE_VAR(v1) \
	#v1 ": " << (v1)
#define TRACE_VAR2(v1, v2) \
	TRACE_VAR(v1) << ", " << TRACE_VAR(v2)
#define TRACE_VAR3(v1, v2, v3) \
	TRACE_VAR2(v1, v2) << ", " << TRACE_VAR(v3)
#define TRACE_VAR4(v1, v2, v3, v4) \
	TRACE_VAR3(v1, v2, v3) << ", " << TRACE_VAR(v4)
#define TRACE_VAR5(v1, v2, v3, v4, v5) \
	TRACE_VAR4(v1, v2, v3, v4) << ", " << TRACE_VAR(v5)
#define TRACE_VAR6(v1, v2, v3, v4, v5, v6) \
	TRACE_VAR5(v1, v2, v3, v4, v5) << ", " << TRACE_VAR(v6)
#define TRACE_VAR7(v1, v2, v3, v4, v5, v6, v7) \
	TRACE_VAR6(v1, v2, v3, v4, v5, v6) << ", " << TRACE_VAR(v7)
#define TRACE_VAR8(v1, v2, v3, v4, v5, v6, v7, v8) \
	TRACE_VAR7(v1, v2, v3, v4, v5, v6, v7) << ", " << TRACE_VAR(v8)
#define TRACE_VAR9(v1, v2, v3, v4, v5, v6, v7, v8, v9) \
	TRACE_VAR8(v1, v2, v3, v4, v5, v6, v7, v8) << ", " << TRACE_VAR(v9)
#define TRACE_VAR10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) \
	TRACE_VAR9(v1, v2, v3, v4, v5, v6, v7, v8, v9) << ", " << TRACE_VAR(v10)
#define TRACE_VAR11(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) \
	TRACE_VAR10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) << ", " << TRACE_VAR(v11)

#define UNKNOWN_VAR(v) \
	"Unknown " << TRACE_VAR(v)
#define TRACE_PTR(p) \
     #p ": " << "{" << p << ", " << (p ? *p : 0) << "}"
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

template<typename IteratorT>
void printTitle(std::ostream &os, const std::string &contName, IteratorT first, IteratorT last);

template<typename IteratorT>
void printRange(std::ostream &os, const std::string &contName, IteratorT first, IteratorT last);
template<typename ContT>
void printContainer(std::ostream &os, const std::string &contName, const ContT &cont);

template<typename IteratorT>
void printRangeMap(std::ostream &os, const std::string &contName, IteratorT first, IteratorT last);
template<typename MapT>
void printMap(std::ostream &os, const std::string &contName, const MapT &cont);

}
//-------------------------------------------------------------------------------------------------
#include "StdStream.inl"
