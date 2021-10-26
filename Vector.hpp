#pragma once
#include <iostream>
#include <vector>
namespace ft {

	template<class T, class Alloc = std::allocator<T> >
		class Vector {
			private:
				T *_array;
				size_t _size;
				size_t _capacity;
				Alloc _alloc;
			public:
				explicit Vector(const Alloc& alloc = Alloc()) : _size(0), _capacity(0), _alloc(alloc) {
					_array = _alloc.allocate(_capacity);
					return ;
				}
				size_t size() const {
					return (_size);
				}

				size_t capacity() const {
					return (_capacity);
				}
				/*

				Vector(size_t n, T const &val) {
					size = n;
					capacity = n;
					array = alloc.allocate(capacity + 1);
					for(int i = 0; i < n; i++)
						array[i] = val;
					array[n] = 0;
				}

				template<typename ItType>
				Vector(ItType first, ItType last) {
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
				}

				Vector(ft::Vector<T> const &other) {
					*this = other;
				}

				Vector &operator=(ft::Vector<T> const &other) {
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
				~Vector()i {
					alloc.deallocate(array, capacity + 1);
					return ;
				}*/
		};
}
