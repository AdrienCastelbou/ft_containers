#include <iostream>
#include <vector>
#include "Vector.hpp"

#include <typeinfo>     // typeid

int main() {
	    typedef ft::Iterator_traits<std::vector<int>::iterator>::value_type value_type;

	/*
  typedef std::iterator_traits<ft::Vector<int> >::value_type traits;
  if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
    std::cout << "int* is a random-access iterator";*/
  return 0;
}
