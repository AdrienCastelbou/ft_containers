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
	ft::set<int>::const_iterator it = s.begin();
	ft::set<int>::const_iterator ite = s.end();
	if (it == ite)
		std::cout << "same" << std::endl;
}
