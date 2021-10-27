#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	ft::Vector<std::string> v(n, "hello world");
	ft::Vector<std::string> vv(v);

}
