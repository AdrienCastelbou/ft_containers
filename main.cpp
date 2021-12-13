#include "common.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <map>
#include "map.hpp"

#define NAMESPACE ft


int main () {

	ft::map<int, int> m;
	m[1] = 2;
	ft::map<int, int>::iterator it = m.begin();
	ft::map<int, int>::iterator ite = m.end();
	m.insert(it, ft::make_pair<int, int>(2, 2));
	for (it = m.begin(); it != ite; it++)
		std::cout << it->first << std::endl;
	std::cout << "size: " << m.size() << std::endl;
}
