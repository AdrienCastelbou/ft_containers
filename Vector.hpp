#pragma once
#include <iostream>
#include <vector>
#include "Iterator.hpp"
#include "utils.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
		class vector {

			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////

				typedef T value_type;
				typedef Alloc allocator_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef RandIterator<T> iterator;
				typedef RandIterator<const T> const_iterator;
				typedef RevRandIterator<T> reverse_iterator;
				typedef RevRandIterator<const T> const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
				typedef size_t size_type;

			private:
				value_type *_array;
				size_t _size;
				size_t _capacity;
				allocator_type _alloc;

				///////////////////////////////////////////
				//                                       //
				//                 Utils                 //
				//                                       //
				///////////////////////////////////////////

				void array_deallocation(void) {
					for (size_t i = 0; i < _size; i++)
						_array[i].~value_type();
					_alloc.deallocate(_array,_capacity * sizeof(value_type));
				}

				value_type *array_allocation(size_t cap) {
					value_type *ptr;

					try {
						ptr = _alloc.allocate(cap * sizeof(value_type));
					}
					catch (std::bad_alloc& ba) {
						std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
						return (NULL);
					}
					return (ptr);
				}

				void alloc_new_array(size_t new_cap) {
					value_type *_new = array_allocation(new_cap);

					for(size_t i = 0; i < _size; i++)
					{
						_new[i] = _array[i];
						_array[i].~value_type();
					}
					_alloc.deallocate(_array, _size * sizeof(value_type));
					_capacity = new_cap;
					_array = _new;
				}


				value_type *copy_array(iterator pos, size_t n) {
					value_type *_new = array_allocation(_capacity + n);
					iterator it = this->begin();
					for (int i = 0; it + i != pos; i++)
						_new[i] = *(it + i);
					return (_new);
				}
			public:

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////
				
				explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc) {
					_array = array_allocation(_capacity);
					return ;
				}

				explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) {
					_array = array_allocation(_capacity);
					for (size_t i = 0; i < n; i++)
						_array[i] = val;
					return ;
				}

				template<class InputIt>
					vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
						_size = 0;
						for (InputIt fcpy = first; fcpy != last; fcpy++)
							_size++;
						_capacity = _size;
						_array = array_allocation(_capacity);
						for (int i = 0; first != last; i++)
							_array[i] = *(first + i);
						return ;
					}

				vector (const vector& other) : _size(other._size), _capacity(other._size), _alloc(other._alloc){
					_array = array_allocation(_capacity);
					for (size_t i = 0; i < _size; i++)
						_array[i] = other._array[i];
					return ;
				}

				vector& operator=(vector const& other) {
					if (this != &other)
					{
						_alloc.deallocate(_array, _capacity * sizeof(value_type));
						_size = other._size;
						_capacity = other._capacity;
						_array = array_allocation(_capacity);
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


				~vector() {
					for (size_t i = 0; i < _size; i++)
						_array[i].~value_type();
					_alloc.deallocate(_array,_capacity * sizeof(value_type));
					return ;
				}

				///////////////////////////////////////////
				//                                       //
				//               Iterators               //
				//                                       //
				///////////////////////////////////////////

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
				const_reverse_iterator rbegin() const {
					return (const_reverse_iterator(&_array[_size - 1]));
				}

				const_reverse_iterator rend() const {
					return (const_reverse_iterator(&_array[-1]));
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
					return (std::numeric_limits<size_t>::max() / sizeof (value_type));
				}

				size_t capacity() const {
					return (_capacity);
				}

				bool empty() const {
					if (_size == 0)
						return (true);
					return (false);
				}
				void reserve(size_type n) {
					if (n <= _capacity)
						return ;
					else if (n > max_size())
						throw (std::length_error("vector"));
					value_type *_new;
					_new = array_allocation(n);
					for(size_t i = 0; i != _size; i++)
					{
						_new[i] = _array[i];
						_array[i].~value_type();
					}
					_alloc.deallocate(_array, _capacity * sizeof(value_type));
					_array = _new;
					_capacity = n;
				}

				///////////////////////////////////////////
				//                                       //
				//            Element access             //
				//                                       //
				///////////////////////////////////////////

				value_type& operator[](size_t n) {
					return (_array[n]);
				}

				value_type const& operator[](size_t n) const {
					return (_array[n]);
				}

				reference at (size_type n) {
					if (n >= _size)
						throw std::out_of_range("vector");
					return (_array[n]);
				}
				const_reference at (size_type n) const {
					if (n >= _size)
						throw std::out_of_range("vector");
					return (_array[n]);
				}

				reference front() {
					return (_array[0]);
				}

				const_reference front() const {
					return (_array[0]);
				}
				reference back() {
					return (_array[_size -1]);
				}

				const_reference back() const {
					return (_array[_size -1]);
				}

				///////////////////////////////////////////
				//                                       //
				//              Modifiers                //
				//                                       //
				///////////////////////////////////////////


				void assign (size_type n, const value_type& val) {
					for (size_t i = 0; i < _size; i++)
						_array[i].~value_type();
					_size = n;
					if (_size > _capacity)
					{
						_alloc.deallocate(_array,_capacity * sizeof(value_type));
						_capacity = _size;
						_array = array_allocation(_capacity);
					}
					for (size_t i = 0; i < _size; i++)
						_array[i] = val;
				}

				/*template<class InputIterator>
					void assign(InputIterator first, InputIterator last) {
						typename ft::iterator_traits<InputIterator>::value_type temp = *first;
						for (size_t i = 0; i < _size; i++)
							_array[i].~value_type();
						size_t n = 0;
						for (InputIterator fcpy = first; fcpy != last; fcpy++)
							n++;
						_size = n;
						if (_size > _capacity)
						{
							_alloc.deallocate(_array,_capacity * sizeof(value_type));
							_capacity = _size;
							_array = array_allocation(_capacity);
						}
						for (size_t i = 0; i < _size; i++)
							_array[i] = temp;
					}*/

				void push_back(const value_type& val) {
					if (_size == _capacity)
						alloc_new_array(_capacity + 1);
					_array[_size] = val;
					_size++;
				}

				void pop_back() {
					if (!this->empty())
						_array[_size -= 1].~value_type();
				}

				iterator insert(iterator position, const value_type& val) {
					iterator ite = this->end();
					iterator it = ite - 1;
					value_type *_new = _array;
					if (_size == _capacity)
						_new = copy_array(position, 1);
					int i = 0;
					for (; ite - i != position; i++)
						_new[_size - i] = *(it - i);
					_new[_size - i] = val;
					if (_size == _capacity)
					{
						array_deallocation();
						_array = _new;
						_capacity += 1;
					}
					_size += 1;
					return (iterator(&_array[(_size - 1) - i]));
				}

				void insert(iterator position, size_type n, const value_type& val) {
					iterator ite = this->end();
					iterator it = ite - 1;
					value_type *_new = _array;
					size_type n_size = _size + n;

					if (n_size > _capacity)
						_new = copy_array(position, n_size - _capacity);
					int i = 0;
					for (; ite - i != position; i++)
						_new[n_size - 1 - i] = *(it - i);
					for (size_type j = 0; n - j != 0; j++)
						_new[n_size - 1 - i - j] = val;
					if (n_size > _capacity)
					{
						array_deallocation();
						_array = _new;
						_capacity = n_size;
					}
					_size = n_size;
				}

				template<class InputIterator>
					void insert(iterator position, InputIterator first, InputIterator last) {
						size_t distance = last.getPtr() - first.getPtr();
						iterator ite = this->end();
						iterator it = ite - 1;
						value_type *_new = _array;
						size_type n_size = _size + distance;
						if (n_size > _capacity)
							_new = copy_array(position, n_size - _capacity);
						int i = 0;
						for (; ite - i != position; i++)
							_new[n_size - 1 - i] = *(it - i);
						for (size_type j = 0; first + j != last; j++)
							_new[n_size - (1 + i + j)] = *(first + (distance - j - 1));
						if (n_size > _capacity)
						{
							array_deallocation();
							_array = _new;
							_capacity = n_size;
						}
						_size = n_size;
					}
				///////////////////////////////////////////
				//                                       //
				//              Allocator                //
				//                                       //
				///////////////////////////////////////////

				allocator_type get_allocator() const {
					return (_alloc);
				}


		};
}
