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
	myvector.assign(4, 32);
	NAMESPACE::vector<int>::iterator it = myvector.begin();
	NAMESPACE::vector<int>::iterator ite = myvector.end();
	print_vector(myvector);
	NAMESPACE::vector<int> vv;
	vv.assign(it, ite);
	vv.assign(it, it);
	print_vector(vv);
}

