#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	ft::Vector<int>::reverse_iterator it = v.rbegin();
	ft::Vector<int>::reverse_iterator ite = v.rend();
	for(;it != ite;it++)
		std::cout << *it << std::endl;

}
