#include "Vector.hpp"

template<typename T>
ft::Vector<T>::Vector() {
	size = 0;
	capacity = 0;
	array = alloc.allocate(capacity + 1);
	*array = 0;
	return ;
}

template<typename T>
ft::Vector<T>::Vector(size_t n, T const &val) {
	size = n;
	capacity = n;
	array = alloc.allocate(capacity + 1);
	for(int i = 0; i < n; i++)
		array[i] = val;
	array[n] = 0;
	return ;
}

template<typename T>
template<typename ItType>
ft::Vector<T>::Vector(ItType first, ItType last) {
	size = 0;
	for(ItType fcpy = first; fcpy != last; fcpy++)
		size++;
	capacity = size;
	array = alloc.allocate(capacity + 1);
	for (int i = 0; first != last; first++)
	{
		array[i] = *first;
		i++;
	}
	array[size] = 0;
	return ;
}

template<typename T>
ft::Vector<T>::Vector(ft::Vector<T> const &other) {
	*this = other;
}
template<typename T>
ft::Vector<T> &ft::Vector<T>::operator=(ft::Vector<T> const &other) {
	if (this != &other)
	{
		this->alloc.deallocate(array, capacity + 1);
		this->size = other.size;
		this->capacity = other.capacity;
		this->array = alloc.allocate(capacity + 1);
		for (int i = 0; i != size; i < size)
			this->array[i] = other.array[i];
		this->array[size] = 0;
	}
	return (*this);
}

template<typename T>
ft::Vector<T>::~Vector() {
	alloc.deallocate(array, capacity + 1);
	return ;
}



int main() {
	size_t n = 3;
	int const val = 1;
	std::vector<int> v(4, 100);
}
