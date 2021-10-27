#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	size_t n = 3;
	const int val = 100;
	const ft::Vector<int> v(n, val);
	ft::Vector<int>::Const_Iterator ite = v.end();
	for (ft::Vector<int>::Const_Iterator it = v.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}
