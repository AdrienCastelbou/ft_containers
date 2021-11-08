#include <iostream>
#include <vector>
#include "Vector.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
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
		NAMESPACE::vector<int>::iterator it = the_vector.begin();
		NAMESPACE::vector<int>::iterator ite = the_vector.end();
		for(; it != ite; it++)
			std::cout << *it << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
};

int main()
{

	NAMESPACE::vector<int> myvector;
	myvector.resize(5, 42);
	NAMESPACE::vector<int> vv;
	vv.resize(4, 42);
	print_vector<int>(myvector);
	print_vector<int>(vv);
	NAMESPACE::swap(myvector, vv);
	print_vector<int>(myvector);
	print_vector<int>(vv);
	if (myvector != vv)
		std::cout << "vectos arent equal" << std::endl;
	else
		std::cout << "vectos are equal" << std::endl;
}

