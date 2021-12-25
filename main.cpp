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
#include <set>
#include <stdlib.h>

int main() {
	ft::map<int, int> m;
	std::cout << std::distance(m.begin(), m.end()) << std::endl;
	ft::set<int> s;
	s.insert(10);
	s.insert(s.begin(), 20);
	int myints[]= {5,10,15};
	s.insert (myints,myints+3);
	ft::set<int> ss;
	if (ss < s)
		std::cout << "lol" << std::endl;
}
