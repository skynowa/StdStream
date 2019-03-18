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

	{
		std::pair<std::string, std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::vector<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::list<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::set<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::multiset<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::deque<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::queue<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::priority_queue<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::stack<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::map<std::string, std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::map<std::string, std::string, std::greater<std::string>> value;
		std::cout << value << std::endl;
	}

	{
		std::multimap<std::string, std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::array<std::string, 0> value;
		std::cout << value << std::endl;
	}

	{
		std::forward_list<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::unordered_map<std::string, std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::unordered_multimap<std::string, std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::unordered_set<std::string> value;
		std::cout << value << std::endl;
	}

	{
		std::unordered_multiset<std::string> value;
		std::cout << value << std::endl;
	}

	{
		auto value = std::make_tuple("test", 3.1, 14, 'y');
		std::cout << value << std::endl;
	}

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------


#if OUTPUT



#endif
