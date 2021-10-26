#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 2;
	ft::Vector<int> v(n);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
}
