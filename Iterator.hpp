#pragma once
#include <iostream>
#include <vector>

namespace ft {

	template<bool Cond, class T>
		class set_is_integral {
			public:
				typedef T type;
				static const bool value = Cond;
		};

	template<typename>
		class is_integral_type : public set_is_integral<false, bool>{};

	template<>
		class is_integral_type<bool> : public set_is_integral<true, bool>{};

	template<>
		class is_integral_type<char> : public set_is_integral<true, char>{};

	template<>
		class is_integral_type<char16_t> : public set_is_integral<true, char16_t>{};

	template<>
		class is_integral_type<char32_t> : public set_is_integral<true, char32_t>{};

	template<>
		class is_integral_type<wchar_t> : public set_is_integral<true, wchar_t>{};

	template<>
		class is_integral_type<signed char> : public set_is_integral<true, signed char>{};

	template<>
		class is_integral_type<short int> : public set_is_integral<true, short int>{};

	template<>
		class is_integral_type<int> : public set_is_integral<true, int>{};

	template<>
		class is_integral_type<long int> : public set_is_integral<true, long int>{};

	template<>
		class is_integral_type<long long int> : public set_is_integral<true, long long int>{};

	template<>
		class is_integral_type<unsigned char> : public set_is_integral<true, unsigned char>{};

	template<>
		class is_integral_type<unsigned short int> : public set_is_integral<true, unsigned short int>{};

	template<>
		class is_integral_type<unsigned int> : public set_is_integral<true, int>{};

	template<>
		class is_integral_type<unsigned long int> : public set_is_integral<true, long int>{};

	template<>
		class is_integral_type<unsigned long long int> : public set_is_integral<true, long long int>{};


	template<class T>
		class is_integral : public is_integral_type<T> {};

	template<bool Cond, class T>
		class enable_if { };

	template<class T>
		class enable_if<true, T> {
			public:
				typedef T type;
		};

	class random_access_iterator_tag {
	};

	class bidirectional_iterator_tag {
	};

	class output_iterator_tag {
	};

	class forward_iterator_tag {
	};

	template<class Iterator>
		class Iterator_traits {
			public:
				typedef typename Iterator::value_type value_type;
				typedef typename Iterator::difference_type difference_type;
				typedef typename Iterator::pointer pointer;
				typedef typename Iterator ::reference reference;
				typedef typename Iterator::iterator_category iterator_category;
		};

	template<class T>
		class Iterator_traits<T*> {
			public:
				typedef T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef T* pointer;
				typedef T& reference;
				typedef ft::random_access_iterator_tag iterator_category;
		};

	template<class T>
		class Iterator_traits<const T*> {
			public:
				typedef const T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef const T* pointer;
				typedef const T& reference;
				typedef ft::random_access_iterator_tag iterator_category;
		};

	template<class InputIterator>
		typename ft::Iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last) {
				return (last - first);
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
					return (temp);
				}
				RandIterator<T> operator+(const difference_type& movement) {
					T* oldPtr = m_ptr;
					m_ptr+=movement;
					RandIterator<T> temp(*this);
					m_ptr = oldPtr;
					return (temp);
				}
				RandIterator<T> operator-(const difference_type& movement) {
					T* oldPtr = m_ptr;
					m_ptr-=movement;
					RandIterator<T> temp(*this);
					m_ptr = oldPtr;
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

	template <class T>
		class RevRandIterator : public ft::Iterator<ft::random_access_iterator_tag, T> {
			public:
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type value_type;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::pointer pointer;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::reference reference;
				typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
			protected:
				T* m_ptr;
			public:
				operator RevRandIterator<const T>() {
					return RevRandIterator<const T>(m_ptr);
				}

				RevRandIterator(T* ptr = nullptr) : m_ptr(ptr) {}
				RevRandIterator(const RevRandIterator<T>& other) : m_ptr(other.m_ptr) {}
				~RevRandIterator() {}
				RevRandIterator<T>& operator=(RevRandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				RevRandIterator<T>& operator=(const RevRandIterator<T>& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				bool operator==(const RevRandIterator<T>& other) const {
					return (m_ptr == other.m_ptr);
				}
				bool operator!=(const RevRandIterator<T>& other) const {
					return (m_ptr != other.m_ptr);
				}
				RevRandIterator<T>& operator+=(const difference_type& movement) {
					m_ptr -= movement;
					return (*this);
				}
				RevRandIterator<T>& operator-=(const difference_type& movement) {
					m_ptr += movement;
					return (*this);
				}
				RevRandIterator<T>& operator++() {
					--m_ptr;
					return (*this);
				}
				RevRandIterator<T>& operator--() {
					++m_ptr;
					return (*this);
				}
				RevRandIterator<T> operator++(int) {
					RevRandIterator<T> temp(*this);
					--m_ptr;
					return (temp);
				}
				RevRandIterator<T> operator--(int) {
					RevRandIterator<T> temp(*this);
					++m_ptr;
					return (temp);
				}
				RevRandIterator<T> operator+(const difference_type& movement) {
					T oldPtr = m_ptr;
					m_ptr-=movement;
					RevRandIterator<T> temp(*this);
					m_ptr = oldPtr;
					return (temp);
				}
				RevRandIterator<T> operator-(const difference_type& movement) {
					T oldPtr = m_ptr;
					m_ptr+=movement;
					RevRandIterator<T> temp(*this);
					m_ptr = oldPtr;
					return (temp);
				}
				difference_type operator-(const RevRandIterator<T>& rawIterator) {
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


}
