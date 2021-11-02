#include <iostream>
#include <vector>
#include "Vector.hpp"


int main()
{
	size_t n = 3;
	const int val = 100;
	const ft::Vector<int> v(n, val);
	std::cout << v.back() << std::endl;
}
