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

	ft::BST_tree<ft::pair<int, int> > tree;
	tree.insert(ft::make_pair<int, int>(5, 3));
	tree.insert(ft::make_pair<int, int>(3, 2));
	tree.insert(ft::make_pair<int, int>(10, 2));
	tree.insert(ft::make_pair<int, int>(7, 2));
	tree.insert(ft::make_pair<int, int>(15, 2));
	tree.insert(ft::make_pair<int, int>(13, 2));
	tree.insert(ft::make_pair<int, int>(25, 2));
	ft::BST_tree<ft::pair<int, int> >::iterator it(tree.begin());
	ft::BST_tree<ft::pair<int, int> >::iterator ite(tree.search(25));
	for(;it != ite; it++)
		std::cout << it->first << std::endl;
	/*tree.erase(tree.search(3));
	tree.show(tree.tree);*/
/*	ft::map<int, int> m;
	m[15] = 51;
	m[1] = 61;
	m[0] = 31;
	m[10] = 51;
	m[8] = 81;
	m[11] = 11;
	m[9] = 91;
	ft::map<int, int>::iterator it = m.begin();
	ft::map<int, int>::iterator ite = it;
	for (int i = 0; i < 3; i++)
		ite++;
	m.erase(it, ite);
	m.show();
	std::cout << m.size() << std::endl;*/
/*	m.erase(9);


	std::cout << "++++" << std::endl;
	m.show();*/
  return 0;
}
