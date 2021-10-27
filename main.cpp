#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	ft::Vector<int> v(n, val);
	std::cout << v.size() << std::endl;
	std::cout << v[2] << std::endl;
}
