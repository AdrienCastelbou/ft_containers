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

  ft::BST<int, int> b(foo);

  ft::BST<int, int> c(bar);
  b.insert(c);
  c = ft::make_pair (3, 3);
  b.insert(c);
  ft::BST<int, int> d(ft::make_pair (11, 4));
  b.insert(d);
  b.show();
  return 0;
}
