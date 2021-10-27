#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	ft::Vector<std::string> v(n, "hello world");
	ft::Vector<std::string> vv;
	vv = v;

	std::cout << v.size() << std::endl;
	std::cout << vv.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << vv.capacity() << std::endl;
}
