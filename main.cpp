#include "common.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

#define NAMESPACE ft


int main ()
{
  ft::stack<int, std::deque<int> > mystack;
  ft::stack<int, std::deque<int> > s(mystack);
  if (mystack >= s)
	  std::cout << "moore" << std::endl;
  else
	  std::cout << "same" << std::endl;

  return 0;
}
