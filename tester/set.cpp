#include <iostream>
#include <string>
#include <deque>
#if 0//CREATE A REAL STL EXAMPLE
	#include <set>
	#include <stack>
	#include <set>
	namespace ft = std;
#else
	#include "../set.hpp"
	#include "../stack.hpp"
	#include "../set.hpp"
#endif

#include <stdlib.h>

template<class T>
void	print_set(T& s) {
	typename T::const_iterator it = s.begin();
	typename T::const_iterator ite = s.end();
	std::cout << "SET CONTENT :" << std::endl;
	for(; it != ite; it++)
		std::cout << *it<< std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "SET SIZE :" << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << "SET MAX SIZE :" << std::endl;
	std::cout << s.max_size() << std::endl;
	std::cout << "IS EMPTY ? ";
	if (s.empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	std::cout << "----------" << std::endl;
}

void	set_constructor() {
	std::cout << "\x1B[32mCONSTRUCTORS TEST \033[0m" << std::endl;
	std::cout << "EMPTY CONSTRUCTOR :" << std::endl;
	ft::set<int> s1;
	print_set(s1);
	std::cout << "----------" << std::endl;
	std::cout << "RANGE CONSTRUCTOR :" << std::endl;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	ft::set<int> s2(s1.begin(), s1.end());
	print_set(s2);
	std::cout << "----------" << std::endl;
	std::cout << "COPY CONSTRUCTOR :" << std::endl;
	ft::set<int> s3(s2);
	print_set(s3);
	std::cout << "----------" << std::endl;
}

void	set_iterator() {

	std::cout << "\x1B[32mITERATORS TEST \033[0m" << std::endl;
	ft::set<int> s;
	for (int i = 0; i < 10; i++)
		s.insert(i);
	std::cout << "ITERATOR TEST :" << std::endl;
	ft::set<int>::const_iterator it = s.begin();
	ft::set<int>::const_iterator ite = s.end();
	for(; it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "REVERSE ITERATOR TEST :" << std::endl;
	ft::set<int>::const_reverse_iterator rit = s.rbegin();
	ft::set<int>::const_reverse_iterator rite = s.rend();
	for(; rit != rite; rit++)
		std::cout << (*rit) << std::endl;
	std::cout << "CHECK SET CONTENT:" << std::endl;
	print_set(s);
}

void	set_capacity() {
	ft::set<int> s;
	ft::set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	std::cout << "\x1B[32mCAPACITY TEST \033[0m" << std::endl;
	std::cout << "INITIALY EMPTY SET : " << std::endl;
	print_set(s);
	std::cout << "INITIALY NO EMPTY SET : " << std::endl;
	print_set(s1);
	print_set(s1);
}

void	set_modifiers() {
	ft::set<int> s;
	for (int i = 0; i < 10; i++)
		s.insert(i);
	ft::set<int>s1;
	std::cout << "\x1B[32mMODIFIERS TEST \033[0m" << std::endl;
	std::cout << "INSERT TEST : " << std::endl;
	std::cout << "TEST 1 : WITH HINT" << std::endl;
	s.insert(s.begin(), 42);
	print_set(s1);
	std::cout << "TEST 2 : SINGLE ELEMENT" << std::endl;
	s.insert(21);
	print_set(s1);
	std::cout << "TEST 3 : RANGE" << std::endl;
	s1.insert(++s.begin(), --s.end());
	print_set(s1);
	std::cout << "ERASE TEST" << std::endl;
	std::cout << "TEST 1 : SINGLE ELEMENT BY KEY" << std::endl;
	s1.erase(3);
	std::cout << "TEST 1 : SINGLE ELEMENT BY IT" << std::endl;
	s1.erase(s1.begin());
	print_set(s1);
	std::cout << "TEST 2 : RANGE" << std::endl;
	s1.erase(s1.begin(), s1.end());
	print_set(s1);
	std::cout << "SWAP TEST : " << std::endl;
	std::cout << "V BEFORE SWAP : " << std::endl;
	print_set(s);
	std::cout << "S1 BEFORE SWAP : " << std::endl;
	print_set(s1);
	s1.swap(s);
	std::cout << "V AFTER SWAP : " << std::endl;
	print_set(s);
	std::cout << "S1 AFTER SWAP : " << std::endl;
	print_set(s1);
	std::cout << "CLEAR TEST : " << std::endl;
	s1.clear();
	print_set(s1);
}

void	set_observer() {
	ft::set<int> s;
	ft::set<int> s1(s.key_comp());

	std::cout << "\x1B[32mOBSERVER TEST \033[0m" << std::endl;
	if (typeid(s.key_comp()) == typeid(s1.key_comp()))
		std::cout << "KEY COMPARATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	if (typeid(s.value_comp()) == typeid(s1.value_comp()))
		std::cout << "VALUE COMPARATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
}

void	set_operations() {
	ft::set<int> s;
	for (int i = 0; i < 10; i++)
		s.insert(i);
	std::cout << "\x1B[32mOPERATIONS TEST \033[0m" << std::endl;
	std::cout << "FIND TEST : " << std::endl;
	std::cout << "Try to find 5 ...";
	ft::set<int>::const_iterator it = s.find(5);
	ft::set<int>::const_iterator ite = s.end();
	if (it != ite)
	{
		std::cout << "Find ! That is the next : " << std::endl; 
		for(; it != ite; it++)
			std::cout << *it << std::endl;
	}
	else
		std::cout << "NOT FOUND" << std::endl;
	it = s.find(42);
	if (it != ite)
	{
		std::cout << "Find ! That is the next : " << std::endl; 
		for(; it != ite; it++)
			std::cout << *it << std::endl;
	}
	else
		std::cout << "NOT FOUND" << std::endl;
	std::cout << "COUNT TEST :" << std::endl;
	std::cout << "In M, 5 appears " << s.count(5) << ", and 42 apperas " << s.count(42) << std::endl;
	std::cout << "LOWER BOUND TEST :" << std::endl;

	std::cout << "TRY WITH 5 :" << std::endl;
	it = s.lower_bound(5);
	for (; it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "UPPER BOUND TEST :" << std::endl;

	std::cout << "TRY WITH 8 :" << std::endl;
	it = s.lower_bound(8);
	for (; it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "UPPER BOUND TEST :" << std::endl;
	std::cout << "TRY WITH 42 :" << std::endl;
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator > range = s.equal_range(42);
	for (; range.first != range.second; range.first++)
		std::cout << *range.first << std::endl;
}


void	set_allocator() {
	ft::set<int> s;
	ft::set<int> s1(s.key_comp(), s.get_allocator());

	std::cout << "\x1B[32mALLOCATOR TEST \033[0m" << std::endl;
	if (typeid(s.get_allocator()) == typeid(s1.get_allocator()))
		std::cout << "ALLOCATORS ARE SAME" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
}

void	set_operators() {
	ft::set<int> s;
	ft::set<int> s1(s);
	ft::set<int> s2;
	for (int i = 0; i < 10; i++)
		s2.insert(i);

	std::cout << "\x1B[32mOPERATOR TEST \033[0m" << std::endl;
	if (s == s1)
		std::cout << "V && S1 ARE SAME" << std::endl;
	if (s != s2)
		std::cout << "V && S2 ARE DIFFERENTS" << std::endl;
	if (s < s2)
		std::cout << "V IS LESS THAN S2" << std::endl;
	if (s2 > s1)
		std::cout << "S2 IS MORE THAN S1" << std::endl;
	if (s1 >= s1)
		std::cout << "V IS MORE OR EQUAL TO S1" << std::endl;
}

void	set_non_member_swap() {
	ft::set<int> s;
	ft::set<int> s1;
	for (int i = 0; i < 10; i++)
		s1.insert(i);
	std::cout << "\x1B[32mNON MEMBER SWAP TEST \033[0m" << std::endl;
	std::cout << "V BEFORE SWAP : " << std::endl;
	print_set(s);
	std::cout << "S1 BEFORE SWAP : " << std::endl;
	print_set(s1);
	ft::swap(s, s1);
	std::cout << "V AFTER SWAP : " << std::endl;
	print_set(s);
	std::cout << "S1 AFTER SWAP : " << std::endl;
	print_set(s1);
}

int		main() {

	set_constructor();
	set_iterator();
	set_capacity();
	set_modifiers();
	set_allocator();
	set_observer();
	set_operations();
	set_operators();
	set_non_member_swap();
}
