#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	std::vector<int> v(n, val);
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();

	for(;it != ite;it++)
		std::cout << *it << std::endl;
}
