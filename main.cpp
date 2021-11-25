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
/*  ft::pair <int,int> foo;
  ft::pair <int,int> bar;

  foo = ft::make_pair (3,20);
  bar = ft::make_pair (2,'A');

  ft::BST<int, int> *b = new ft::BST<int, int>(foo);
  ft::BST<int, int>* start = b;
  start->reorder_tree(start, start);
  ft::BST<int, int> *c = new ft::BST<int, int>(bar);
  start->insert(c, start);

  //start->show();
  //std::cout << std::endl << "////" << std::endl;
  c = new ft::BST<int, int>(ft::make_pair (1, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (11, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (16, 3));
  start->insert(c, start);
  c = new ft::BST<int, int>(ft::make_pair (15, 3));
  start->insert(c, start);
  //start->right_rotation(&start->search(12), &start);
  start->show();*/
	ft::pair <int,int> foo = ft::make_pair (3,20);
	ft::BST<int, int> *b = new ft::BST<int, int>(foo);
	ft::BidIterator<ft::BST<int, int> > it(b);
	ft::pair <int,int> fo = ft::make_pair (3,20);
	ft::BST<int, int> *c = new ft::BST<int, int>(fo);
	ft::BidIterator<ft::BST<int, int> > itt(c);
	std::cout << (it != itt) << std::endl;
	/*std::map<int, int> m;
	m[1] = 2;
	std::map<int, int>::iterator it = m.begin();*/
  return 0;
}
