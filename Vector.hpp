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
					_array = _alloc.allocate(_capacity * sizeof(T));
					return ;
				}

				explicit Vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : _size(n), _capacity(n), _alloc(alloc) {
					_array = _alloc.allocate(_capacity * sizeof(T));
					for (int i = 0; i < n; i++)
						_array[i] = val;
					return ;
				}

				template<class InputIt>
					Vector(InputIt first, InputIt last, const Alloc& alloc = Alloc()) : _alloc(alloc) {
						_size = 0;
						for (InputIt fcpy = first; fcpy != last; fcpy++)
							_size++;
						_capacity = _size;
						_array = _alloc.allocate(_capacity * sizeof(T));
						for (int i = 0; (first + i) != last; i++)
							_array[i] = *(first + i);
						return ;
					}

				Vector (const Vector& other) : _size(other._size), _capacity(other._capacity), _alloc(other._alloc){
					_array = _alloc.allocate(_capacity * sizeof(T));
					for (int i = 0; i < _size; i++)
						_array[i] = other._array[i];
					return ;
				}

				size_t size() const {
					return (_size);
				}

				size_t capacity() const {
					return (_capacity);
				}
				/*

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
