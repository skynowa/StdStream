/**
 * \file  Print.h
 * \brief std::ostream printers
 */


#pragma once

//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <sstream>
#include <typeinfo>
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
namespace stdstream
{

class Print final
	/// Printer for std::ostream
{
public:
///\name ctors, dtor
///\{
	Print(const std::string &contName, const std::string &delimiter, std::ostream &os);
	~Print() = default;

	Print() = delete;
	Print(const Print &) = delete;
	Print(Print &&) = delete;
	Print & operator = (const Print &) = delete;
	Print & operator = (Print &&) = delete;
///\}

	template<typename IteratorT>
	void range(IteratorT first, IteratorT last);
			///< container's range
	template<typename ContT>
	void container(const ContT &cont);
			///< all container
	template<typename T1, typename T2>
	void container(const std::pair<T1, T2> &cont);
			///< std::pair

public: // static
	template<typename T>
	static std::string typeNameDemangle(const T &cont);
			///< demangled type name
private:
	const std::string _contName;
	const std::string _delimiter;

	std::ostream &_os;

	template<typename IteratorT>
	void _title(IteratorT first, IteratorT last);
			///< contatiner title (name)
};

} // ns stdstream
//-------------------------------------------------------------------------------------------------
#include "Print.inl"
