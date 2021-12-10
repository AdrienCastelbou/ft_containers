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
	m[15] = 51;
	m[1] = 61;
	m[0] = 31;
	m[31] = 31;
	m[19] = 31;
	m[14] = 31;
	ft::map<int, int>::iterator it= m.begin();
	ft::map<int, int>::iterator ite = m.begin();
	for(int i = 0; i < 3; i++)
		ite++;
	m.erase(it, ite);
	m.show();
	//std::cout << m.size() << std::endl;
/*	m.erase(9);


	std::cout << "++++" << std::endl;
	m.show();*/
  return 0;
}
