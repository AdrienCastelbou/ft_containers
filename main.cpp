#include <iostream>
#include <vector>
#include "Vector.hpp"

#ifndef NAMESPACE
# define NAMESPACE std
#endif

#define FALSE 0

template<class T>
void print_vector(NAMESPACE::vector<T> &the_vector)
{
    std::cout << "size : " << the_vector.size() << std::endl;
    std::cout << "max_size : " << the_vector.max_size() << std::endl;
    std::cout << "capacity : " << the_vector.capacity() << std::endl;
    std::cout << "empty : " << the_vector.empty() << std::endl;
    if (the_vector.empty() == FALSE)
    {
        std::cout << "front_value " << the_vector.front() << std::endl;
        std::cout << "back_value " << the_vector.back() << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
};

int main()
{

	NAMESPACE::vector<int> myvector;
	NAMESPACE::vector<int>::iterator it = myvector.begin();
	NAMESPACE::vector<int>::iterator ite = myvector.end();
	myvector.resize(5, 42);
	myvector.reserve(10);
	for (int i=0; i<1; i++)
	{
		print_vector<int>(myvector);
		myvector.resize(8, 33);
		it = myvector.begin();
		ite = myvector.end();
		for(; it != ite; it++)
			std::cout << *it << std::endl;
	}
	it = myvector.begin();
	ite = myvector.end();
	print_vector<int>(myvector);
}
/*
int main ()
{
//	size_t n = 3;
//	const int val = 100;
	std::vector<int> first;
  //std::vector<int> second;

  first.assign (7,100);             // 7 ints with a value of 100
  std::vector<int>::iterator it = first.begin();
  std::vector<int>::iterator ite = first.end();
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
