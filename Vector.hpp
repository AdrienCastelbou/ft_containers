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

				/*
				class Iterator {
					private:
						T* m_ptr;

					public:
						Iterator(T* ptr) : m_ptr(ptr) {
							return ;
						}
						
						T& operator*() {
							return (*m_ptr);
						}

						const T& operator*() const {
							return (*m_ptr);
						}

						T* operator->() {
							return (m_ptr);
						}

						const T* operator->() const {
							return (m_ptr);
						}

						T& operator[](int n) {
							return (*(m_ptr + n));
						}

						const T& operator[](int n) const {
							return (*(m_ptr + n));
						}

						Iterator& operator++() {
							m_ptr++;
							return (*this);
						}

						Iterator operator++(int) {
							Iterator tmp = *this;
							++(*this);
							return (tmp);
						}

						Iterator& operator--() {
							m_ptr--;
							return (*this);
						}

						Iterator operator--(int) {
							Iterator tmp = *this;
							--(*this);
							return (tmp);
						}

						Iterator& operator+(int n) {
							Iterator tmp = *this;
							return (tmp += n);
						}

						Iterator& operator+=(int n) {
							m_ptr += n;
							return (*this);
						}

						Iterator& operator-(int n) {
							Iterator tmp = *this;
							return (tmp -= n);
						}

						Iterator& operator-=(int n) {
							m_ptr -= n;
							return (*this);
						}

						bool operator<(const Iterator& b) {
							return (m_ptr < b.m_ptr);
						}

						bool operator<=(const Iterator& b) {
							return (m_ptr <= b.m_ptr);
						}

						bool operator>(const Iterator& b) {
							return (m_ptr > b.m_ptr);
						}

						bool operator>=(const Iterator& b) {
							return (m_ptr >= b.m_ptr);
						}

						bool operator==(const Iterator& b) {
							return (m_ptr == b.m_ptr);
						}

						bool operator!=( const Iterator& b) const {
							return (m_ptr != b.m_ptr);
						}
				};

				class Const_Iterator {
					private:
						const T* m_ptr;

					public:
						Const_Iterator(T* ptr) : m_ptr(ptr) {
							return ;
						}
						
						const T& operator*() {
							return (*m_ptr);
						}

						const T& operator*() const {
							return (*m_ptr);
						}

						const T* operator->() {
							return (m_ptr);
						}

						const T* operator->() const {
							return (m_ptr);
						}

						const T& operator[](int n) {
							return (*(m_ptr + n));
						}

						const T& operator[](int n) const {
							return (*(m_ptr + n));
						}

						Const_Iterator& operator++() {
							m_ptr++;
							return (*this);
						}

						Const_Iterator operator++(int) {
							Const_Iterator tmp = *this;
							++(*this);
							return (tmp);
						}

						Const_Iterator& operator--() {
							m_ptr--;
							return (*this);
						}

						Const_Iterator operator--(int) {
							Const_Iterator tmp = *this;
							--(*this);
							return (tmp);
						}

						Const_Iterator& operator+(int n) {
							Const_Iterator tmp = *this;
							return (tmp += n);
						}

						Const_Iterator& operator+=(int n) {
							m_ptr += n;
							return (*this);
						}

						Const_Iterator& operator-(int n) {
							Const_Iterator tmp = *this;
							return (tmp -= n);
						}

						Const_Iterator& operator-=(int n) {
							m_ptr -= n;
							return (*this);
						}

						bool operator<(const Const_Iterator& b) {
							return (m_ptr < b.m_ptr);
						}

						bool operator<=(const Const_Iterator& b) {
							return (m_ptr <= b.m_ptr);
						}

						bool operator>(const Const_Iterator& b) {
							return (m_ptr > b.m_ptr);
						}

						bool operator>=(const Const_Iterator& b) {
							return (m_ptr >= b.m_ptr);
						}

						bool operator==(const Const_Iterator& b) {
							return (m_ptr == b.m_ptr);
						}

						bool operator!=( const Const_Iterator& b) const {
							return (m_ptr != b.m_ptr);
						}
				};

				Iterator begin() {
					return (Iterator(&_array[0]));
				}

				Const_Iterator begin() const {
					return (Const_Iterator(&_array[0]));
				}

				Iterator end() {
					return (Iterator(&_array[_size]));
				}
				
				Const_Iterator end() const {
					return (Const_Iterator(&_array[_size]));
				}

				*/

				///////////////////////////////////////////
				//                                       //
				//               Capacity                //
				//                                       //
				///////////////////////////////////////////

				size_t size() const {
					return (_size);
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
