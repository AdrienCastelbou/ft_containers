#include "common.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "map.hpp"

#define NAMESPACE ft


int main () {
  ft::pair <int,int> foo;
  ft::pair <int,int> bar;

  foo = ft::make_pair (10,20);
  bar = ft::make_pair (14,'A');

  ft::BST<int, int> *b = new ft::BST<int, int>(foo);
  ft::BST<int, int>* start = b;
  ft::BST<int, int> *c = new ft::BST<int, int>(bar);
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (12, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (11, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (16, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (15, 3));
  start->insert(c, start);
  start->show();
  std::cout << "<;;;;;;>" << std::endl;
  start->left_rotation(&start->search(14), &start);
  start->show();
  return 0;
}
