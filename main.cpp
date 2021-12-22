#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
	#include "set.hpp"
#endif

#include <stdlib.h>

int main() {
	ft::set<int> s;
	s.insert(10);
	s.insert(s.begin(), 20);
	ft::set<int>::iterator it = s.begin();
	ft::set<int>::iterator ite = s.end();
	for(; it != ite; it++)
	std::cout << *it << std::endl;
}
