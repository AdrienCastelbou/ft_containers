#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../map.hpp"
	#include "../stack.hpp"
	#include "../vector.hpp"
#endif

#include <stdlib.h>


int		main() {
	ft::stack<int, ft::vector<int> > s;
	ft::vector<int> v(3, 42);
	ft::stack<int, ft::vector<int> > s1(v);
	std::cout << "\x1B[32mSTACK TEST \033[0m" << std::endl;

	std::cout << "S size = " << s.size() << ", is empty ? " << s.empty() << std::endl;

	std::cout << "S1 size = " << s1.size() << ", is empty ? " << s1.empty() << std::endl;
	std::cout << "S1 top is " << s1.top() << std::endl;
	s1.top() += 42;
	std::cout << "After modification, S1 top is " << s1.top() << std::endl;
	for (int i = 0; i < 10; i++)
		s.push(i);
	std::cout << "0 -> 9 added to S, no lets pop this" << std::endl;
	std::cout << "Popping out elements ..." ;
	while (!s.empty())
	{
		std::cout << " " << s.top() ;
		s.pop();
	}
	std::cout << std::endl;

}
