/**
 * \file  main.cpp
 * \brief
 */


#include <iostream>
#include "StdStream.h"

//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	{
		// a_value.print(a_os);
	}

	// std::pair
	{
		std::pair<std::string, std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "111"};
		std::cout << value << std::endl << std::endl;
	}

	// std::vector
	{
		std::vector<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::list
	{
		std::list<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa1", "bbb2", "ccc3"};
		std::cout << value << std::endl << std::endl;
	}

	// std::set
	{
		std::set<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::multiset
	{
		std::multiset<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::deque
	{
		std::deque<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::queue
	{
		std::queue<std::string> value;
		std::cout << value << std::endl;

		value.push("aaa");
		value.push("bbb");
		value.push("ccc");
		std::cout << value << std::endl << std::endl;
	}

	// std::priority_queue
	{
		std::priority_queue<std::string> value;
		std::cout << value << std::endl;

		value.push("aaa");
		value.push("bbb");
		value.push("ccc");
		std::cout << value << std::endl << std::endl;
	}

	// std::stack
	{
		std::stack<std::string> value;
		std::cout << value << std::endl;

		value.push("aaa");
		value.push("bbb");
		value.push("ccc");
		std::cout << value << std::endl << std::endl;
	}

	// std::map
	{
		std::map<std::string, std::string> value;
		std::cout << value << std::endl;

		value = {{"aaa", "000"}, {"bbb", "111"}};
		std::cout << value << std::endl << std::endl;
	}

	// std::map
	{
		std::map<std::string, std::string, std::greater<std::string>> value;
		std::cout << value << std::endl;

		value = {{"aaa", "000"}, {"bbb", "111"}};
		std::cout << value << std::endl << std::endl;
	}

	// std::multimap
	{
		std::multimap<std::string, std::string> value;
		std::cout << value << std::endl;

		value = {{"aaa", "000"}, {"bbb", "111"}};
		std::cout << value << std::endl << std::endl;
	}

	// std::array
	{
		std::array<std::string, 0> value;
		std::cout << value << std::endl;

		std::array<std::string, 3> value3 {"a", "b", "c"};
		std::cout << value3 << std::endl << std::endl;
	}

	// std::forward_list
	{
		std::forward_list<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::unordered_map
	{
		std::unordered_map<std::string, std::string> value;
		std::cout << value << std::endl;

		value = {{"aaa", "000"}, {"bbb", "111"}};
		std::cout << value << std::endl << std::endl;
	}

	// std::unordered_multimap
	{
		std::unordered_multimap<std::string, std::string> value;
		std::cout << value << std::endl;

		value = {{"aaa", "000"}, {"bbb", "111"}};
		std::cout << value << std::endl << std::endl;
	}

	// std::unordered_set
	{
		std::unordered_set<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::unordered_multiset
	{
		std::unordered_multiset<std::string> value;
		std::cout << value << std::endl;

		value = {"aaa", "aaa", "bbb", "ccc"};
		std::cout << value << std::endl << std::endl;
	}

	// std::tuple
	{
		std::tuple<std::string, double, int, char> value;
		std::cout << value << std::endl;

		value = std::make_tuple("test", 3.1, 14, 'y');
		std::cout << value << std::endl << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
