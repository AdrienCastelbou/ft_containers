#include <iostream>
#include <vector>
#include "vector.hpp"
#include <list>

#define TESTED_NAMESPACE std
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
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	print_vector(vct);


	std::cout << (it_ == it.base()) << std::endl;
	std::cout << *it_ << ", " << *it << ", " << *(it.base()) << std::endl;
	/*std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;*/

	return (0);
}
