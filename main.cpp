#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	ft::Vector<int>::iterator it = v.end();
	it--;
	std::cout << *v.insert(it, 4) << std::endl;;
	ft::Vector<int>::iterator ite = v.end();
	std::cout << "size = " << v.size() << ", capacity = " << v.capacity() << std::endl;
	it = v.begin();
	for(;it != ite;it++)
		std::cout << *it << std::endl;
}
