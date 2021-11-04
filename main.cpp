#include <iostream>
#include <vector>
#include "Vector.hpp"

int main()
{
	if (ft::is_integral<float>::value)
		std::cout << "okkk" << std::endl;
}

/*int main ()
{
//	size_t n = 3;
//	const int val = 100;
  ft::Vector<int> first;
  //std::vector<int> second;

  first.assign (7,100);             // 7 ints with a value of 100
  ft::Vector<int>::iterator it = first.begin();
  ft::Vector<int>::iterator ite = first.end();
  for (;it != ite; it++)
	  std::cout << *it << std::endl; 
  first.assign (3,60);
  first.push_back(21);
  it = first.begin();
  ite = first.end();
  for (;it != ite; it++)
	  std::cout << *it << std::endl; 
  
  //it=first.begin()+1;

  //second.assign (it,first.end()-1); // the 5 central values of first

  std::cout << "Size of first: " << int (first.capacity()) << '\n';
  //std::cout << "Size of second: " << int (second.size()) << '\n';
  return 0;
}*/
