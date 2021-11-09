#include <iostream>
#include <vector>
#include "vector.hpp"
#include <list>
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

#define TESTED_TYPE int

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);
	NAMESPACE::vector<TESTED_TYPE> v(3, 100);

	NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	print_vector(vct);
/*
	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	print_vector(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	print_vector(vct);*/
	return (0);
}

