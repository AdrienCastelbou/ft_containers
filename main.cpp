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
	m[3] = 3;
	m[5] = 51;
	ft::map<int, int>::reverse_iterator it = m.rbegin();
	ft::map<int, int>::reverse_iterator ite = m.rend();
	for(;it != ite; it++)
	std::cout << it->first << std::endl;
}
