#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	ft::Vector<int>::Iterator ite = v.end();
	for (ft::Vector<int>::Iterator it = v.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}
