#include <iostream>
#include <vector>
#include "vector.hpp"
#include <list>

#define TESTED_NAMESPACE ft
#define FALSE 0

template<class T>
void print_vector(TESTED_NAMESPACE::vector<T> &the_vector)
{
    std::cout << "size : " << the_vector.size() << std::endl;
    std::cout << "max_size : " << the_vector.max_size() << std::endl;
    std::cout << "capacity : " << the_vector.capacity() << std::endl;
    std::cout << "empty : " << the_vector.empty() << std::endl;
    if (the_vector.empty() == FALSE)
    {
		TESTED_NAMESPACE::vector<int>::iterator it = the_vector.begin();
		TESTED_NAMESPACE::vector<int>::iterator ite = the_vector.end();
		for(; it != ite; it++)
			std::cout << *it << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
};

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);
	std::cout << "mmm" << std::endl;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);

	std::cout << "OK" << std::endl;
	return (0);
}
