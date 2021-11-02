#include <iostream>
#include <vector>
#include "Vector.hpp"


int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.push_back(2);
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.push_back(1);
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
		v.push_back(31);
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.push_back(10);
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	std::cout << "REMOVE" << std::endl;
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.pop_back();
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.pop_back();
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.pop_back();
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
	v.pop_back();
	std::cout << v.back() << ", size ="  << v.size() << ", cap = "<< v.capacity() << std::endl;
}
