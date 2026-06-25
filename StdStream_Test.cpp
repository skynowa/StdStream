/**
 * \file  main.cpp
 * \brief
 */


#include <cassert>
#include <cstdlib>
#include <sstream>
#include <string>

#include "StdStream.h"
//-------------------------------------------------------------------------------------------------
template<typename T>
class TestAllocator
{
public:
	using value_type = T;

	TestAllocator() = default;

	template<typename OtherT>
	TestAllocator(const TestAllocator<OtherT> &)
	{
	}

	T * allocate(std::size_t count)
	{
		return std::allocator<T>().allocate(count);
	}

	void deallocate(T *ptr, std::size_t count)
	{
		std::allocator<T>().deallocate(ptr, count);
	}
};

template<typename T1, typename T2>
bool operator == (const TestAllocator<T1> &, const TestAllocator<T2> &)
{
	return true;
}

template<typename T1, typename T2>
bool operator != (const TestAllocator<T1> &, const TestAllocator<T2> &)
{
	return false;
}
//-------------------------------------------------------------------------------------------------
struct IntHash
{
	std::size_t operator () (int value) const
	{
		return std::hash<int>()(value);
	}
};

struct IntEqual
{
	bool operator () (int lhs, int rhs) const
	{
		return lhs == rhs;
	}
};
//-------------------------------------------------------------------------------------------------
template<typename ValueT>
std::string toString(const ValueT &value)
{
	std::ostringstream os;
	os << value;

	return os.str();
}

void assertContains(const std::string &value, const std::string &part)
{
	assert(value.find(part) != std::string::npos);
}
//-------------------------------------------------------------------------------------------------
void testPair()
{
	const std::pair<std::string, std::string> emptyValue;
	assert(toString(emptyValue) == "std::pair: {,}");

	const std::pair<std::string, std::string> value {"aaa", "111"};
	assert(toString(value) == "std::pair: {aaa,111}");
}
//-------------------------------------------------------------------------------------------------
void testSequenceContainers()
{
	{
		std::vector<std::string> emptyValue;
		assert(toString(emptyValue) == "std::vector (size=0): {}");

		std::vector<std::string, TestAllocator<std::string>> value {"aaa", "bbb", "ccc"};
		assert(toString(value) == "std::vector (size=3): {aaa,bbb,ccc}");
	}

	{
		std::list<std::string, TestAllocator<std::string>> value {"aaa1", "bbb2", "ccc3"};
		assert(toString(value) == "std::list (size=3): {aaa1,bbb2,ccc3}");
	}

	{
		std::deque<std::string, TestAllocator<std::string>> value {"aaa", "bbb", "ccc"};
		assert(toString(value) == "std::deque (size=3): {aaa,bbb,ccc}");
	}

	{
		std::forward_list<std::string, TestAllocator<std::string>> value {"aaa", "bbb", "ccc"};
		assert(toString(value) == "std::forward_list (size=3): {aaa,bbb,ccc}");
	}

	{
		std::array<std::string, 0> emptyValue;
		assert(toString(emptyValue) == "std::array (size=0): {}");

		std::array<std::string, 3> value {"a", "b", "c"};
		assert(toString(value) == "std::array (size=3): {a,b,c}");
	}
}
//-------------------------------------------------------------------------------------------------
void testOrderedAssociativeContainers()
{
	{
		std::set<int, std::greater<int>, TestAllocator<int>> value {1, 2, 2, 3};
		assert(toString(value) == "std::set (size=3): {3,2,1}");
	}

	{
		std::multiset<int, std::greater<int>, TestAllocator<int>> value {1, 2, 2, 3};
		assert(toString(value) == "std::multiset (size=4): {3,2,2,1}");
	}

	{
		using ValueT = std::pair<const int, int>;
		std::map<int, int, std::greater<int>, TestAllocator<ValueT>> value {{1, 10}, {2, 20}};
		assert(toString(value) == "std::map (size=2): {std::pair: {2,20}\nstd::pair: {1,10}}");
	}

	{
		using ValueT = std::pair<const int, int>;
		std::multimap<int, int, std::greater<int>, TestAllocator<ValueT>> value {{1, 10}, {2, 20}, {2, 22}};
		assert(toString(value) == "std::multimap (size=3): {std::pair: {2,20}\nstd::pair: {2,22}\nstd::pair: {1,10}}");
	}
}
//-------------------------------------------------------------------------------------------------
void testUnorderedAssociativeContainers()
{
	{
		using ValueT = std::pair<const int, int>;
		std::unordered_map<int, int, IntHash, IntEqual, TestAllocator<ValueT>> value {{1, 10}, {2, 20}};
		const std::string out = toString(value);

		assertContains(out, "std::unordered_map (size=2): {");
		assertContains(out, "std::pair: {1,10}");
		assertContains(out, "std::pair: {2,20}");
	}

	{
		using ValueT = std::pair<const int, int>;
		std::unordered_multimap<int, int, IntHash, IntEqual, TestAllocator<ValueT>> value {{1, 10}, {2, 20}, {2, 22}};
		const std::string out = toString(value);

		assertContains(out, "std::unordered_multimap (size=3): {");
		assertContains(out, "std::pair: {1,10}");
		assertContains(out, "std::pair: {2,20}");
		assertContains(out, "std::pair: {2,22}");
	}

	{
		std::unordered_set<int, IntHash, IntEqual, TestAllocator<int>> value {1, 2, 2, 3};
		const std::string out = toString(value);

		assertContains(out, "std::unordered_set (size=3): {");
		assertContains(out, "1");
		assertContains(out, "2");
		assertContains(out, "3");
	}

	{
		std::unordered_multiset<int, IntHash, IntEqual, TestAllocator<int>> value {1, 2, 2, 3};
		const std::string out = toString(value);

		assertContains(out, "std::unordered_multiset (size=4): {");
		assertContains(out, "1");
		assertContains(out, "2");
		assertContains(out, "3");
	}
}
//-------------------------------------------------------------------------------------------------
void testContainerAdaptors()
{
	{
		std::queue<std::string, std::list<std::string>> value;
		value.push("aaa");
		value.push("bbb");
		value.push("ccc");

		assert(toString(value) == "std::queue (size=3): {aaa,bbb,ccc}");
		assert(value.size() == 3);
		assert(value.front() == "aaa");
		assert(value.back() == "ccc");
	}

	{
		std::priority_queue<int, std::vector<int>, std::greater<int>> value;
		value.push(3);
		value.push(1);
		value.push(2);

		assert(toString(value) == "std::priority_queue (size=3): {1,2,3}");
		assert(value.size() == 3);
		assert(value.top() == 1);
	}

	{
		std::stack<std::string, std::vector<std::string>> value;
		value.push("aaa");
		value.push("bbb");
		value.push("ccc");

		assert(toString(value) == "std::stack (size=3): {aaa,bbb,ccc}");
		assert(value.size() == 3);
		assert(value.top() == "ccc");
	}
}
//-------------------------------------------------------------------------------------------------
void testTuple()
{
	const std::tuple<std::string, double, int, char> value = std::make_tuple("test", 3.1, 14, 'y');
	assert(toString(value) == "std::tuple (size=4): {test,3.1,14,y}");

	const std::tuple<> emptyValue;
	assert(toString(emptyValue) == "std::tuple (size=0): {}");
}
//-------------------------------------------------------------------------------------------------
void testTracePtr()
{
	{
		std::string *value {};
		std::ostringstream os;
		os << STD_TRACE_PTR(value);
		const std::string out = os.str();

		assertContains(out, "value: {");
		assertContains(out, "nullptr");
	}

	{
		std::string data {"abc"};
		std::string *value {&data};
		std::ostringstream os;
		os << STD_TRACE_PTR(value);
		const std::string out = os.str();

		assertContains(out, "value: {");
		assertContains(out, ", abc}");
	}

	{
		volatile int data {7};
		volatile int *value {&data};
		std::ostringstream os;
		os << STD_TRACE_PTR(value);
		const std::string out = os.str();

		assertContains(out, "value: {");
		assertContains(out, ", 7}");
	}
}
//-------------------------------------------------------------------------------------------------
int main(int, char **)
{
	testPair();
	testSequenceContainers();
	testOrderedAssociativeContainers();
	testUnorderedAssociativeContainers();
	testContainerAdaptors();
	testTuple();
	testTracePtr();

	return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
