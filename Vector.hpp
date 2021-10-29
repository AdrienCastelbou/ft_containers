#pragma once
#include <iostream>
#include <vector>
#include "Iterator.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
		class Vector {

			private:
				T *_array;
				size_t _size;
				size_t _capacity;
				Alloc _alloc;
			public:


				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////
				
				explicit Vector(const Alloc& alloc = Alloc()) : _size(0), _capacity(0), _alloc(alloc) {
					_array = _alloc.allocate(_capacity * sizeof(T));
					return ;
				}

				explicit Vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc()) : _size(n), _capacity(n), _alloc(alloc) {
					_array = _alloc.allocate(_capacity * sizeof(T));
					for (size_t i = 0; i < n; i++)
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
						for (int i = 0; first != last; i++)
							_array[i] = *(first + i);
						return ;
					}

				Vector (const Vector& other) : _size(other._size), _capacity(other._capacity), _alloc(other._alloc){
					_array = _alloc.allocate(_capacity * sizeof(T));
					for (size_t i = 0; i < _size; i++)
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
						for (size_t i = 0; i < _size; i++)
							_array[i] = other._array[i];
					}
					return (*this);
				}

				///////////////////////////////////////////
				//                                       //
				//              Destructor               //
				//                                       //
				///////////////////////////////////////////


				~Vector() {
					for (size_t i = 0; i < _size; i++)
						_array[i].~T();
					_alloc.deallocate(_array,_capacity * sizeof(T));
					return ;
				}

				///////////////////////////////////////////
				//                                       //
				//               Iterators               //
				//                                       //
				///////////////////////////////////////////

				typedef RandIterator<T> iterator;
				typedef RandIterator<const T> const_iterator;
				typedef RevRandIterator<T> reverse_iterator;
				typedef RevRandIterator<const T> reverse_const_iterator;

				iterator begin() {
					return (iterator(&_array[0]));
				}

				iterator end() {
					return (iterator(&_array[_size]));
				}
				const_iterator begin() const {
					return (const_iterator(&_array[0]));
				}

				const_iterator end() const {
					return (const_iterator(&_array[_size]));
				}

				reverse_iterator rbegin() {
					return (reverse_iterator(&_array[_size - 1]));
				}

				reverse_iterator rend() {
					return (reverse_iterator(&_array[-1]));
				}
				reverse_const_iterator rbegin() const {
					return (const_iterator(&_array[_size - 1]));
				}

				reverse_const_iterator rend() const {
					return (reverse_const_iterator(&_array[-1]));
				}


				///////////////////////////////////////////
				//                                       //
				//               Capacity                //
				//                                       //
				///////////////////////////////////////////

				size_t size() const {
					return (_size);
				}

				size_t max_size() const {
					return (std::numeric_limits<size_t>::max() / sizeof (T));
				}

				size_t capacity() const {
					return (_capacity);
				}

				///////////////////////////////////////////
				//                                       //
				//            Element access             //
				//                                       //
				///////////////////////////////////////////

				T& operator[](size_t n) {
					return (_array[n]);
				}

				T const& operator[](size_t n) const {
					return (_array[n]);
				}
		};
}
