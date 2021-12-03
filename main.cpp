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
	m[10] = 51;
	m[8] = 81;
	m[11] = 11;
	m[9] = 91;
	m.erase(1);

	m.show();
/*	m.erase(9);


	std::cout << "++++" << std::endl;
	m.show();*/
  return 0;
  /*  ft::pair <int,int> foo;
  ft::pair <int,int> bar;

  foo = ft::make_pair (15,20);
  bar = ft::make_pair (7,'A');

  ft::BST<int, int> *b = new ft::BST<int, int>(foo);
  b->insert_green();
  ft::BST<int, int>* start = b;
  start->reorder_tree(b, start);
  ft::BST<int, int> *c = new ft::BST<int, int>(bar);
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (18, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (2, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (5, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (3, 3));
  start->insert(c, start);
   c = new ft::BST<int, int>(ft::make_pair (6, 3));
  start->insert(c, start);
 c = new ft::BST<int, int>(ft::make_pair (9, 3));
  start->insert(c, start);
 c = new ft::BST<int, int>(ft::make_pair (11, 3));
  start->insert(c, start);
 c = new ft::BST<int, int>(ft::make_pair (10, 3));
  start->insert(c, start);
 c = new ft::BST<int, int>(ft::make_pair (14, 3));
  start->insert(c, start);
 c = new ft::BST<int, int>(ft::make_pair (13, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (16, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (19, 3));
  start->insert(c, start);

  start = start->parent();
  start->show();*/
  return 0;
}
