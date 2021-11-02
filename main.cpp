#include <iostream>
#include <vector>
#include "Vector.hpp"


int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
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
