#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../map.hpp"
	#include "../stack.hpp"
	#include "../vector.hpp"
#endif

#include <stdlib.h>

template<class T>
void	print_vector(T& v) {
	typename T::const_iterator it = v.begin();
	typename T::const_iterator ite = v.end();
	std::cout << "VECTOR CONTENT :" << std::endl;
	for(; it != ite; it++)
		std::cout << *it  << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "VECTOR SIZE :" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << "VECTOR CAPACITY :" << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << "VECTOR MAX SIZE :" << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << "IS EMPTY ? ";
	if (v.empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;

	std::cout << "----------" << std::endl;
}

void	vector_constructor() {
	std::cout << "\x1B[32mCONSTRUCTORS TEST \033[0m" << std::endl;
	std::cout << "EMPTY CONSTRUCTOR :" << std::endl;
	ft::vector<int> v1;
	print_vector(v1);
	std::cout << "----------" << std::endl;
	std::cout << "FILL CONSTRUCTOR :" << std::endl;
	ft::vector<int> v2(3, 42);
	print_vector(v2);
	std::cout << "----------" << std::endl;
	std::cout << "RANGE CONSTRUCTOR :" << std::endl;
	ft::vector<int> v3(v2.begin(), v2.end());
	print_vector(v3);
	std::cout << "----------" << std::endl;
	std::cout << "COPY CONSTRUCTOR :" << std::endl;
	ft::vector<int> v4(v3);
	print_vector(v4);
	std::cout << "----------" << std::endl;
}

void	vector_iterator() {

	std::cout << "\x1B[32mITERATORS TEST \033[0m" << std::endl;
	ft::vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	std::cout << "ITERATOR TEST :" << std::endl;
	ft::vector<int>::const_iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.end();
	for(; it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "RANDOM ACCESS ITERATOR TEST" << std::endl;
	it = v.begin();
	std::cout << *(it + 3) << std::endl;
	std::cout << *(it += 7) << std::endl;
	std::cout << *(it - 5) << std::endl;
	std::cout << *(it -= 2) << std::endl;
	std::cout << "REVERSE ITERATOR TEST :" << std::endl;
	ft::vector<int>::const_reverse_iterator rit = v.rbegin();
	ft::vector<int>::const_reverse_iterator rite = v.rend();
	for(; rit != rite; rit++)
		std::cout << *rit << std::endl;
	std::cout << "REVERSE RANDOM ACCESS ITERATOR TEST" << std::endl;
	rit = v.rbegin();
	std::cout << *(rit + 3) << std::endl;
	std::cout << *(rit += 7) << std::endl;
	std::cout << *(rit - 5) << std::endl;
	std::cout << *(rit -= 2) << std::endl;
	std::cout << "CHECK VECTOR CONTENT:" << std::endl;
	print_vector(v);
}

void	vector_capacity() {
	ft::vector<int> v;
	ft::vector<int> v1(10, 42);

	std::cout << "\x1B[32mCAPACITY TEST \033[0m" << std::endl;
	std::cout << "INITIALY EMPTY VECTOR : " << std::endl;
	print_vector(v);
	std::cout << "INITIALY NO EMPTY VECTOR : " << std::endl;
	print_vector(v1);
	std::cout << "RESIZE TEST :" << std::endl;
	v.resize(3);
	v1.resize(0);
	std::cout << "INITIALY EMPTY VECTOR : " << std::endl;
	print_vector(v);
	std::cout << "INITIALY NO EMPTY VECTOR : " << std::endl;
	print_vector(v1);
	std::cout << "RESERVE TEST :" << std::endl;
	v.reserve(5);
	v1.reserve(5);
	std::cout << "INITIALY EMPTY VECTOR : " << std::endl;
	print_vector(v);
	std::cout << "INITIALY NO EMPTY VECTOR : " << std::endl;
	print_vector(v1);
}

void	vector_access() {
	ft::vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	std::cout << "\x1B[32mACCESS TEST \033[0m" << std::endl;
	std::cout << "ACCESS OPERATOR [] :" << std::endl;
	for(unsigned long i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	std::cout << "ACCESS OPERATOR AT() :" << std::endl;
	for(unsigned long i = 0; i < v.size(); i++)
		std::cout << v.at(i) << std::endl;
	std::cout << "FRONT && BACK ACCESS OPERATOR :" << std::endl;
	std::cout << "FRONT : " << v.front() << ", BACK : " << v.back() << std::endl;
}

void	vector_modifiers() {
	ft::vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	ft::vector<int>v1;
	std::cout << "\x1B[32mMODIFIERS TEST \033[0m" << std::endl;
	std::cout << "ASSIGN TEST : " << std::endl;
	std::cout << "TEST 1 : RANGE" << std::endl;
	v1.assign(v.begin(), v.end()),
	print_vector(v1);
	std::cout << "TEST 2 : FILL" << std::endl;
	v1.assign(5, 42);
	print_vector(v1);
	std::cout << "PUSH_BACK TEST : " << std::endl;
	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::iterator ite = v.end();
	for(; it != ite; it++)
		v1.push_back(*it);
	print_vector(v1);
	std::cout << "POP_BACK TEST : " << std::endl;
	 it = v.begin();
	for(; it != ite; it++)
		v1.pop_back();
	print_vector(v1);
	std::cout << "INSERT TEST : " << std::endl;
	std::cout << "TEST 1 : SINGLE ELEMENT" << std::endl;
	v1.insert(v1.begin(), *v.begin());
	print_vector(v1);
	std::cout << "TEST 2 : FILL" << std::endl;
	v1.insert(v1.end(), 10, 21);
	print_vector(v1);
	std::cout << "TEST 3 : RANGE" << std::endl;
	v1.insert(v1.begin() + 5, v.begin(), v.end());
	print_vector(v1);
	std::cout << "ERASE TEST" << std::endl;
	std::cout << "TEST 1 : SINGLE ELEMENT" << std::endl;
	v1.erase(v1.begin());
	print_vector(v1);
	std::cout << "TEST 2 : RANGE" << std::endl;
	v1.erase(v1.begin(), v1.end() - 5);
	print_vector(v1);
	std::cout << "SWAP TEST : " << std::endl;
	std::cout << "V BEFORE SWAP : " << std::endl;
	print_vector(v);
	std::cout << "V1 BEFORE SWAP : " << std::endl;
	print_vector(v1);
	v1.swap(v);
	std::cout << "V AFTER SWAP : " << std::endl;
	print_vector(v);
	std::cout << "V1 AFTER SWAP : " << std::endl;
	print_vector(v1);
	std::cout << "CLEAR TEST : " << std::endl;
	v1.clear();
	print_vector(v1);
}

int		main() {

	//vector_constructor();
	//vector_iterator();
	//vector_capacity();
	//vector_access();
	vector_modifiers();
}
