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
	ft::map<int, int> n;
	n = m;
	std::cout << n[1] << std::endl;
	if (m == n)
		std::cout << "ya" << std::endl;
	else
		std::cout << "UwU" << std::endl;
}
