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

	std::map<int, int> m;
	m[1] = 2;
	std::map<int, int> n;
	n[2] = 2;
	if (m >= n)
		std::cout << "ya" << std::endl;
	else
		std::cout << "UwU" << std::endl;
}
