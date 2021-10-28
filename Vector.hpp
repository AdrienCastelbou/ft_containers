#pragma once
#include <iostream>
#include <vector>

namespace ft {

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
		class Iterator {
			public:
				typedef T value_type;
				typedef Distance difference_type;
				typedef Pointer pointer;
				typedef Reference reference;
				typedef Category iterator_category;
		};

	class random_access_iterator_tag {
	};

	template <class T>
		class RandIterator : public ft::Iterator<ft::random_access_iterator_tag, T> {
			public:
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type value_type;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::pointer pointer;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::reference reference;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
			protected:
				T* m_ptr;
			public:
				RandIterator(T* ptr = nullptr) : m_ptr(ptr) {}
				RandIterator(const RandIterator<T>& other) : m_ptr(other.m_ptr) {}
				~RandIterator() {}
				RandIterator<T>& operator=(RandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				RandIterator<T>& operator=(const RandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				bool operator==(const RandIterator<T>& other) const {
					return (m_ptr == other.m_ptr);
				}
				bool operator!=(const RandIterator<T>& other) const {
					return (m_ptr != other.m_ptr);
				}
				RandIterator<T>& operator+=(const difference_type& movement) {
					m_ptr += movement;
					return (*this);
				}
				RandIterator<T>& operator-=(const difference_type& movement) {
					m_ptr -= movement;
					return (*this);
				}
				RandIterator<T>& operator++() {
					++m_ptr;
					return (*this);
				}
				RandIterator<T>& operator--() {
					--m_ptr;
					return (*this);
				}
				RandIterator<T> operator++(int) {
					RandIterator<T> temp(*this);
					++m_ptr;
					return (temp);
				}
				RandIterator<T> operator--(int) {
					RandIterator<T> temp(*this);
					--m_ptr;
					return temp;
				}
				RandIterator<T> operator+(const difference_type& movement) {
					T oldPtr = m_ptr;
					m_ptr+=movement;
					RandIterator<T> temp(*this);
					m_ptr = oldPtr;
					return (temp);
				}
				RandIterator<T> operator-(const difference_type& movement) {
					T oldPtr = m_ptr;
					m_ptr-=movement;
					RandIterator<T> temp(*this);
					m_ptr = oldPtr;
					return temp;
				}
				difference_type operator-(const RandIterator<T>& rawIterator) {
					return std::distance(rawIterator.getPtr(),this->getPtr());
				}
				T& operator*() {
					return *m_ptr;
				}
				const T& operator*()const {
					return *m_ptr;
				}
				T* operator->(){
					return m_ptr;
				}
				T* getPtr()const {
					return m_ptr;
				}
				const T* getConstPtr()const {
					return m_ptr;
				}
		};

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
