#pragma once
#include <iostream>
#include <vector>

namespace ft {


	class random_access_iterator_tag {
	};

	class bidirectional_iterator_tag {
	};

	class output_iterator_tag {
	};

	class forward_iterator_tag {
	};

	template<class Iterator>
		class iterator_traits {
			public:
				typedef typename Iterator::value_type value_type;
				typedef typename Iterator::difference_type difference_type;
				typedef typename Iterator::pointer pointer;
				typedef typename Iterator ::reference reference;
				typedef typename Iterator::iterator_category iterator_category;
		};

	template<class T>
		class iterator_traits<T*> {
			public:
				typedef T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;
				typedef ft::random_access_iterator_tag iterator_category;
		};

	template<class T>
		class iterator_traits<const T*> {
			public:
				typedef const T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef const T* pointer;
				typedef const T& reference;
				typedef ft::random_access_iterator_tag iterator_category;
		};

	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last) {
			if (typeid(InputIterator::iterator_category) == typeid(ft::random_access_iterator_tag) || typeid(InputIterator::iterator_category) == typeid(std::random_access_iterator_tag))
				return (last - first);
			int i = 0;
			for(; first != last; i++)
				first++;
			return (i);
		}

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
		class Iterator {
			public:
				typedef T value_type;
				typedef Distance difference_type;
				typedef Pointer pointer;
				typedef Reference reference;
				typedef Category iterator_category;
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
				operator RandIterator<const T>() {
					return RandIterator<const T>(m_ptr);
				}

				RandIterator(T* ptr = nullptr) : m_ptr(ptr) {}
				RandIterator(const RandIterator<T>& other) : m_ptr(other.m_ptr) {}
				~RandIterator() {}
				RandIterator& operator=(RandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				RandIterator& operator=(const RandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				bool operator==(const RandIterator<T>& other) const {
					return (m_ptr == other.m_ptr);
				}
				bool operator!=(const RandIterator<T>& other) const {
					return (m_ptr != other.m_ptr);
				}
				RandIterator& operator+=(const difference_type& movement) {
					m_ptr += movement;
					return (*this);
				}
				RandIterator& operator-=(const difference_type& movement) {
					m_ptr -= movement;
					return (*this);
				}
				RandIterator& operator++() {
					++m_ptr;
					return (*this);
				}
				RandIterator& operator--() {
					--m_ptr;
					return (*this);
				}
				RandIterator operator++(int) {
					RandIterator<T> temp(*this);
					++m_ptr;
					return (temp);
				}
				RandIterator operator--(int) {
					RandIterator<T> temp(*this);
					--m_ptr;
					return (temp);
				}
				RandIterator operator+(difference_type movement) const {
					RandIterator temp(m_ptr + movement);
					return (temp);
				}
				RandIterator operator-(difference_type movement) const {
					RandIterator temp(m_ptr - movement);
					return (temp);
				}

				difference_type operator-(const RandIterator<T>& rawIterator) {
					return (ft::distance(rawIterator.getPtr(),this->getPtr()));
				}
				T& operator*() {
					return (*m_ptr);
				}
				const T& operator*()const {
					return (*m_ptr);
				}
				T* operator->(){
					return (m_ptr);
				}
				T* getPtr()const {
					return (m_ptr);
				}
				const T* getConstPtr()const {
					return (m_ptr);
				}
		};

	template<class Iterator>
		class reverse_iterator {
			private:
				Iterator _it;
			public:
				typedef Iterator iterator_type;
				typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
				typedef typename iterator_traits<Iterator>::value_type value_type;
				typedef typename iterator_traits<Iterator>::difference_type difference_type;
				typedef typename iterator_traits<Iterator>::pointer pointer;
				typedef typename iterator_traits<Iterator>::reference reference;

				reverse_iterator() : _it(iterator_type()) {};

				explicit reverse_iterator(iterator_type it) : _it(iterator_type(it)){}

				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it) {}

				///////////////////////////////////////////
				//                                       //
				//       Member functions overloads      //
				//                                       //
				///////////////////////////////////////////

				iterator_type base() const {
					iterator_type it = _it;
					return (iterator_type(it));
				}
				
				reference operator*() const {
					iterator_type it(_it - 1);
					return (*it);
				}

				reverse_iterator operator+(difference_type n) const {
					iterator_type it = _it - n;
					return (reverse_iterator(it));
				}

				reverse_iterator& operator++() {
					--_it;
					return (*this);
				}

				reverse_iterator operator++(int) {
					reverse_iterator temp = *this;
					++(*this);
					return (temp);
				}

				reverse_iterator& operator+=(difference_type n) {
					_it -= n;
					return (*this);
				}

				reverse_iterator operator-(difference_type n) const {
					iterator_type it = _it + n;
					return (reverse_iterator(it));
				}

				reverse_iterator& operator--() {
					++_it;
					return (*this);
				}

				reverse_iterator operator--(int) {
					reverse_iterator temp = *this;
					--(*this);
					return (temp);
				}

				reverse_iterator& operator-=(difference_type n) {
					_it += n;
					return (*this);
				}

				pointer operator->() const {
					return (&(this->operator*()));
				}

				reference operator[](difference_type n) {
					return (this->base()[-n]);
				}

				///////////////////////////////////////////
				//                                       //
				//     Non-member function overloads     //
				//                                       //
				///////////////////////////////////////////

				friend bool operator==(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it == rhs._it);
				}

				friend bool operator!=(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it != rhs._it);
				}

				friend bool operator<=(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it >= rhs._it);
				}

				friend bool operator<(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it > rhs._it);
				}

				friend bool operator>(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it < rhs._it);
				}

				friend bool operator>=(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it <= rhs._it);
				}

				friend reverse_iterator operator+ (difference_type n, const reverse_iterator& rev_it) {
					return (rev_it + n);
				}

				friend difference_type operator-(const reverse_iterator& lhs, const reverse_iterator& rhs) {
					return (lhs._it - rhs._it);
				}
		};
}
