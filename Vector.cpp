#include "Vector.hpp"

template<typename T>
ft::Vector<T>::Vector() {
	size = 0;
	capacity = 0;
	array = alloc.allocate(0);
	return ;
}

template<typename T>
ft::Vector<T>::Vector(size_t n, T const &val) {
	size = n;
	capacity = n;
	array = alloc.allocate(n);
	for(int i = 0; i < n; i++)
		array[i] = new T(val);
	return ;
}
