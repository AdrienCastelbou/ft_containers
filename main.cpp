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
	ft::map<int, int>::iterator it = m.begin();
	ft::map<int, int>::iterator ite = m.end();
	m.erase(it, ite);
	std::cout << "size: " << m.size() << std::endl;
}
