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
					return temp;
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
					return temp;
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
					return temp;
				}
				difference_type operator-(const RevRandIterator<T>& rawIterator) {
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


}
