#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	ft::Vector<int>::iterator it = v.begin();
	ft::Vector<int>::iterator ite = v.end();
	std::cout << ft::distance(it.getPtr(), ite.getPtr()) << std::endl;;
}
