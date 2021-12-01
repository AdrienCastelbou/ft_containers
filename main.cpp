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
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('z');  // itlow points to b
  //itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  //	std::cout << itlow->second << std::endl;
  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;/*  ft::pair <int,int> foo;
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
