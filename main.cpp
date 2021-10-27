#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	ft::Vector<ft::Vector<int> > v(1);
	std::cout << v.size() << std::endl;
}
