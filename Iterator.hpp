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
				
				RandIterator& operator=(RandIterator& other) {
					m_ptr = other.m_ptr;
					return (*this);
				}
				
				RandIterator& operator=(const RandIterator& other) {
					m_ptr = other.m_ptr;
					return (*this);
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
					RandIterator temp(*this);
					++m_ptr;
					return (temp);
				}

				reference operator[](difference_type n) {
					return (this->m_ptr[n]);
				}

				RandIterator operator--(int) {
					RandIterator temp(*this);
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

				difference_type operator-(const RandIterator& rawIterator) const {
					return (this->m_ptr - rawIterator.m_ptr);
				}

				reference operator*() {
					return (*m_ptr);
				}
				const reference operator*() const {
					return (*m_ptr);
				}
				pointer operator->(){
					return (m_ptr);
				}
				pointer getPtr() const {
					return (m_ptr);
				}
				const pointer getConstPtr() const {
					return (m_ptr);
				}

				friend RandIterator operator+ (difference_type n, const RandIterator& it) {
					return (it + n);
				}

				friend bool operator==(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr == rhs.m_ptr);
				}
				
				friend bool operator!=(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr != rhs.m_ptr);
				}

				friend bool operator<=(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr <= rhs.m_ptr);
				}

				friend bool operator<(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr < rhs.m_ptr);
				}

				friend bool operator>(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr > rhs.m_ptr);
				}

				friend bool operator>=(const RandIterator& lhs, const RandIterator& rhs) {
					return (lhs.m_ptr >= rhs.m_ptr);
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
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()){}


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
				//  Friend Non-member function overloads //
				//                                       //
				///////////////////////////////////////////

				friend bool operator==(const reverse_iterator& lhs, const reverse_iterator& rhs);
				template<class L, class R>
					friend bool operator==(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend bool operator!=(const reverse_iterator& lhs, const reverse_iterator& rhs) ;
				template<class L, class R>
					friend bool operator!=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend bool operator<=(const reverse_iterator& lhs, const reverse_iterator& rhs) ;
				template<class L, class R>
					friend bool operator<=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend bool operator<(const reverse_iterator& lhs, const reverse_iterator& rhs) ;
				template<class L, class R>
					friend bool operator<(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend bool operator>(const reverse_iterator& lhs, const reverse_iterator& rhs) ;
				template<class L, class R>
					friend bool operator>(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend bool operator>=(const reverse_iterator& lhs, const reverse_iterator& rhs) ;
				template<class L, class R>
					friend bool operator>=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);

				friend reverse_iterator operator+ (difference_type n, const reverse_iterator& rev_it) {
			return (rev_it + n);
		}

				friend difference_type operator-(const reverse_iterator& lhs, const reverse_iterator& rhs);
				template<class L, class R>
					friend bool operator-(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs);
		};

	///////////////////////////////////////////
	//                                       //
	//Rev_iter Non-member function overloads //
	//                                       //
	///////////////////////////////////////////


	///		Equal Operator		///
	
	template<class Iterator>
		bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() == rhs.base());
		}

	template<class L, class R>
		bool operator==(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() == rhs.base());
		}

	///		Inequal Operator	///

	template<class Iterator>
		bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs._it != rhs._it);
		}

	template<class L, class R>
		bool operator!=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() != rhs.base());
		}

	///	Equal or Less Operator	///

	template<class Iterator> 
		bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs._it >= rhs._it);
		}

	template<class L, class R>
		bool operator<=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() <= rhs.base());
		}

	///		Less Operator		///

	template<class Iterator> 
		bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs._it > rhs._it);
		}

	template<class L, class R>
		bool operator<(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() < rhs.base());
		}

	///		More Operator		///

	template<class Iterator> 
		bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs._it < rhs._it);
		}

	template<class L, class R>
		bool operator>(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() > rhs.base());
		}

	///	Equal or More Operator	///

	template<class Iterator> 
		bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs._it <= rhs._it);
		}

	template<class L, class R>
		bool operator>=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() >= rhs.base());
		}

	///		Add Operator	///

/*	template<class Iterator> 
		reverse_iterator<Iterator> operator+ (typename iterator_traits<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
			return (rev_it + n);
		}*/

	//	Substract Operator	///

	template<class Iterator> 
		typename iterator_traits<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() - rhs.base());
		}

		template<class L, class R>
			bool operator-(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
				return (lhs.base() - rhs.base());
			}
}
