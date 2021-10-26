#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	ft::Vector<int> v;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
}
