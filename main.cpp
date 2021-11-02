#include <iostream>
#include <vector>
#include "Vector.hpp"


int main()
{
	size_t n = 3;
	const int val = 100;
	const ft::Vector<int> v(n, val);
	try {
	std::cout << v.at(2) << std::endl;
	}
  catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }

}
