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
   ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  ft::pair<char,int> highest = *mymap.end();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

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
