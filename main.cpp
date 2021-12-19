#include "common.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <map>
#include "map.hpp"

#define NAMESPACE ft
#define T1 int
#define T2 std::string

template<class M>
void printMap(M m) {
	NAMESPACE::map<T1, T2>::iterator it = m.begin();
	NAMESPACE::map<T1, T2>::iterator ite = m.end();
	for(; it != ite; it++)
		std::cout << it->first << ": " << it->second << std::endl;
	std::cout << "------------------" << std::endl;
}


int main () {
	const ft::map<int, int> m ;
	ft::map<int, int>::const_iterator it = m.begin();
}
