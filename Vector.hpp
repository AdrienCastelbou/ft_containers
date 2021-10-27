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

				Vector& operator=(Vector const& other) {
					if (this != &other)
					{
						_alloc.deallocate(_array, _capacity * sizeof(T));
						_size = other._size;
						_capacity = other._capacity;
						_array = _alloc.allocate(_capacity * sizeof(T));
						for (int i = 0; i < _size; i++)
							_array[i] = other._array[i];
					}
					return (*this);
				}

				~Vector() {
					for (int i = 0; i < _size; i++)
						_array[i].~T();
					_alloc.deallocate(_array,_capacity * sizeof(T));
					return ;
				}
				size_t size() const {
					return (_size);
				}

				size_t capacity() const {
					return (_capacity);
				}
				/*
				~Vector()i {
					alloc.deallocate(array, capacity + 1);
					return ;
				}*/
		};
}
