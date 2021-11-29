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
  ft::pair <int,int> foo;
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
  start->show();
/*
  ft::BST_iterator<ft::BST<int, int> > it(&start->search(19));
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;

  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;
  std::cout <<  (it--)->first << std::endl;

  std::cout <<  (it--)->first << std::endl;

  std::map<int, int> m;
  m[1] = 1;
  m[2] = 2;
  m[3] = 3;
	std::map<int, int>::iterator i = m.begin();
	std::cout << (++i)->first << std::endl;
  std::pair <int,int> baar;

  baar = std::make_pair (10,20);*/
  return 0;
}
