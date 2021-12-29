#include <iostream>
#include <string>
#include <deque>
#if 1//CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <map>
	namespace ft = std;
#else
	#include "../map.hpp"
	#include "../stack.hpp"
	#include "../map.hpp"
#endif

#include <stdlib.h>

template<class T>
void	print_map(T& v) {
	typename T::const_iterator it = v.begin();
	typename T::const_iterator ite = v.end();
	std::cout << "MAP CONTENT :" << std::endl;
	for(; it != ite; it++)
		std::cout << it->first  << ", " << it->second << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "MAP SIZE :" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << "MAP MAX SIZE :" << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << "IS EMPTY ? ";
	if (v.empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	std::cout << "----------" << std::endl;
}

void	map_constructor() {
	std::cout << "\x1B[32mCONSTRUCTORS TEST \033[0m" << std::endl;
	std::cout << "EMPTY CONSTRUCTOR :" << std::endl;
	ft::map<int, int> v1;
	print_map(v1);
	std::cout << "----------" << std::endl;
	std::cout << "RANGE CONSTRUCTOR :" << std::endl;
	for (int i = 0; i < 10; i++)
		v1[i] = i + 10;
	ft::map<int, int> v2(v1.begin(), v1.end());
	print_map(v2);
	std::cout << "----------" << std::endl;
	std::cout << "COPY CONSTRUCTOR :" << std::endl;
	ft::map<int, int> v3(v2);
	print_map(v3);
	std::cout << "----------" << std::endl;
}

void	map_iterator() {

	std::cout << "\x1B[32mITERATORS TEST \033[0m" << std::endl;
	ft::map<int, int> v;
	for (int i = 0; i < 10; i++)
		v[i] = i + 10;
	std::cout << "ITERATOR TEST :" << std::endl;
	ft::map<int, int>::const_iterator it = v.begin();
	ft::map<int, int>::const_iterator ite = v.end();
	for(; it != ite; it++)
		std::cout << it->first << ", " << it->second << std::endl;
	std::cout << "REVERSE ITERATOR TEST :" << std::endl;
	ft::map<int, int>::const_reverse_iterator rit = v.rbegin();
	ft::map<int, int>::const_reverse_iterator rite = v.rend();
	for(; rit != rite; rit++)
		std::cout << (*rit).first << ", " << (*rit).second << std::endl;
	std::cout << "CHECK MAP CONTENT:" << std::endl;
	print_map(v);
}

void	map_capacity() {
	ft::map<int, int> v;
	ft::map<int, int> v1;
	for (int i = 0; i < 10; i++)
		v1[i] = i + 10;
	std::cout << "\x1B[32mCAPACITY TEST \033[0m" << std::endl;
	std::cout << "INITIALY EMPTY MAP : " << std::endl;
	print_map(v);
	std::cout << "INITIALY NO EMPTY MAP : " << std::endl;
	print_map(v1);
	print_map(v1);
}

void	map_access() {
	ft::map<int, int> v;
	for (int i = 0; i < 10; i++)
		v[i] = i + 10;
	std::cout << "\x1B[32mACCESS TEST \033[0m" << std::endl;
	std::cout << "ACCESS OPERATOR [] :" << std::endl;
	for(unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	v[0] = 42;
	std::cout << "AFTER MODIFICATION W/ []" << std::endl;
	for(unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
}

void	map_modifiers() {
	ft::map<int, int> v;
	for (int i = 0; i < 10; i++)
		v[i] = i + 10;
	ft::map<int, int>v1;
	std::cout << "\x1B[32mMODIFIERS TEST \033[0m" << std::endl;
	std::cout << "INSERT TEST : " << std::endl;
	std::cout << "TEST 1 : WITH HINT" << std::endl;
	v.insert(v.begin(), ft::make_pair(42, 21));
	print_map(v1);
	std::cout << "TEST 2 : SINGLE ELEMENT" << std::endl;
	v.insert(ft::make_pair(21, 42));
	print_map(v1);
	std::cout << "TEST 3 : RANGE" << std::endl;
	v1.insert(++v.begin(), --v.end());
	print_map(v1);
	std::cout << "ERASE TEST" << std::endl;
	std::cout << "TEST 1 : SINGLE ELEMENT BY KEY" << std::endl;
	v1.erase(3);
	std::cout << "TEST 1 : SINGLE ELEMENT BY IT" << std::endl;
	v1.erase(v1.begin());
	print_map(v1);
	std::cout << "TEST 2 : RANGE" << std::endl;
	v1.erase(v1.begin(), v1.end());
	print_map(v1);
	std::cout << "SWAP TEST : " << std::endl;
	std::cout << "V BEFORE SWAP : " << std::endl;
	print_map(v);
	std::cout << "V1 BEFORE SWAP : " << std::endl;
	print_map(v1);
	v1.swap(v);
	std::cout << "V AFTER SWAP : " << std::endl;
	print_map(v);
	std::cout << "V1 AFTER SWAP : " << std::endl;
	print_map(v1);
	std::cout << "CLEAR TEST : " << std::endl;
	v1.clear();
	print_map(v1);
}

void	map_observer() {
	ft::map<int, int> v;
	ft::map<int, int> v1(v.key_comp());

	std::cout << "\x1B[32mOBSERVER TEST \033[0m" << std::endl;
	if (typeid(v.key_comp()) == typeid(v1.key_comp()))
		std::cout << "KEY COMPARATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	if (typeid(v.value_comp()) == typeid(v1.value_comp()))
		std::cout << "VALUE COMPARATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
}

void	map_operations() {
	ft::map<int, int> v;
	for (int i = 0; i < 10; i++)
		v[i] = i + 10;
	std::cout << "\x1B[32mOPERATIONS TEST \033[0m" << std::endl;
	std::cout << "FIND TEST : " << std::endl;
	std::cout << "Try to find 5 ...";
	ft::map<int, int>::const_iterator it = v.find(5);
	ft::map<int, int>::const_iterator ite = v.end();
	if (it != ite)
	{
		std::cout << "Find ! That is the next : " << std::endl; 
		for(; it != ite; it++)
			std::cout << it->first << ", " << it->second << std::endl;
	}
	else
		std::cout << "NOT FOUND" << std::endl;
	it = v.find(42);
	if (it != ite)
	{
		std::cout << "Find ! That is the next : " << std::endl; 
		for(; it != ite; it++)
			std::cout << it->first << ", " << it->second << std::endl;
	}
	else
		std::cout << "NOT FOUND" << std::endl;
	std::cout << "COUNT TEST :" << std::endl;
	std::cout << "In M, 5 appears " << v.count(5) << ", and 42 apperas " << v.count(42) << std::endl;
	std::cout << "LOWER BOUND TEST :" << std::endl;

	std::cout << "TRY WITH 5 :" << std::endl;
	it = v.lower_bound(5);
	for (; it != ite; it++)
		std::cout << it->first << ", " << it->second << std::endl;
	std::cout << "UPPER BOUND TEST :" << std::endl;

	std::cout << "TRY WITH 8 :" << std::endl;
	it = v.lower_bound(8);
	for (; it != ite; it++)
		std::cout << it->first << ", " << it->second << std::endl;
	std::cout << "UPPER BOUND TEST :" << std::endl;
	std::cout << "TRY WITH 42 :" << std::endl;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator > range = v.equal_range(42);
	for (; range.first != range.second; range.first++)
		std::cout << range.first->first << ", " << range.second->second << std::endl;
}


void	map_allocator() {
	ft::map<int, int> v;
	ft::map<int, int> v1(v.key_comp(), v.get_allocator());

	std::cout << "\x1B[32mALLOCATOR TEST \033[0m" << std::endl;
	if (typeid(v.get_allocator()) == typeid(v1.get_allocator()))
		std::cout << "ALLOCATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
}

void	map_operators() {
	ft::map<int, int> v;
	ft::map<int, int> v1(v);
	ft::map<int, int> v2;
	for (int i = 0; i < 10; i++)
		v2[i] = i + 10;

	std::cout << "\x1B[32mOPERATOR TEST \033[0m" << std::endl;
	if (v == v1)
		std::cout << "V && V1 ARE SAME" << std::endl;
	if (v != v2)
		std::cout << "V && V2 ARE DIFFERENTS" << std::endl;
	if (v < v2)
		std::cout << "V IS LESS THAN V2" << std::endl;
	if (v2 > v1)
		std::cout << "V2 IS MORE THAN V1" << std::endl;
	if (v1 >= v1)
		std::cout << "V IS MORE OR EQUAL TO V1" << std::endl;
}

void	map_non_member_swap() {
	ft::map<int, int> v;
	ft::map<int, int> v1;
	for (int i = 0; i < 10; i++)
		v1[i] = i + 10;
	std::cout << "\x1B[32mNON MEMBER SWAP TEST \033[0m" << std::endl;
	std::cout << "V BEFORE SWAP : " << std::endl;
	print_map(v);
	std::cout << "V1 BEFORE SWAP : " << std::endl;
	print_map(v1);
	ft::swap(v, v1);
	std::cout << "V AFTER SWAP : " << std::endl;
	print_map(v);
	std::cout << "V1 AFTER SWAP : " << std::endl;
	print_map(v1);
}

int		main() {

	map_constructor();
	map_iterator();
	map_capacity();
	map_access();
	map_modifiers();
	map_allocator();
	map_observer();
	map_operations();
	map_operators();
	map_non_member_swap();
}
