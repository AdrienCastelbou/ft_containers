#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	ft::Vector<int>::const_iterator it = v.begin();
	ft::Vector<int>::const_iterator ite = v.end();

	for(;it != ite;it++)
		std::cout << *it << std::endl;
}
