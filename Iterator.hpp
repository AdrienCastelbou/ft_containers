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
		};

	///////////////////////////////////////////
	//                                       //
	// RanIter Non-member function overloads //
	//                                       //
	///////////////////////////////////////////


	//	Add Operator		//
	template<class T>
		RandIterator<T> operator+ (typename iterator_traits<RandIterator<T> >::difference_type n, const RandIterator<T>& it) {
			return (it + n);
		}


	//	Equal Operator		//

	template<class T>
		bool operator==(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) == &(*rhs));
		}

	template<class L, class R>
		bool operator==(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) == &(*rhs));
		}

	//	Inequal Operator	//
	template<class T>
		bool operator!=(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) != &(*rhs));
		}

	template<class L, class R>
		bool operator!=(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) != &(*rhs));
		}


	//	Less/Equal Operator	//

	template<class T>
		bool operator<=(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) <= &(*rhs));
		}

	template<class L, class R>
		bool operator<=(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) <= &(*rhs));
		}

	//	Less Operator		//

	template<class T>
		bool operator<(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) < &(*rhs));
		}

	template<class L, class R>
		bool operator<(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) < &(*rhs));
		}


	//	More Operator		//

	template<class T>
		bool operator>(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) > &(*rhs));
		}

	template<class L, class R>
		bool operator>(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) > &(*rhs));
		}

	//	More/Equal Operator	//

	template<class T>
		bool operator>=(const RandIterator<T>& lhs, const RandIterator<T>& rhs) {
			return (&(*lhs) >= &(*rhs));
		}

	template<class L, class R>
		bool operator>=(const RandIterator<L>& lhs, const RandIterator<R>& rhs) {
			return (&(*lhs) >= &(*rhs));
		}

				///////////////////////////////////////////
				//                                       //
				//           reverse_iterator            //
				//                                       //
				///////////////////////////////////////////

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

				reverse_iterator() : _it() {};

				explicit reverse_iterator(iterator_type it) : _it(it) {}

				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()){}

				template <class Iter>
					reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}

				///////////////////////////////////////////
				//                                       //
				//       Member functions overloads      //
				//                                       //
				///////////////////////////////////////////

				iterator_type base() const {
					return (_it);
				}
				
				reference operator*() const {
					iterator_type tmp = elem;
					return (*(--tmp));
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
					return (this->base()[-n-1]);
				}


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
			return (lhs.base() != rhs.base());
		}

	template<class L, class R>
		bool operator!=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() != rhs.base());
		}

	///	Equal or Less Operator	///

	template<class Iterator> 
		bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() >= rhs.base());
		}

	template<class L, class R>
		bool operator<=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() >= rhs.base());
		}

	///		Less Operator		///

	template<class Iterator> 
		bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() > rhs.base());
		}

	template<class L, class R>
		bool operator<(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() > rhs.base());
		}

	///		More Operator		///

	template<class Iterator> 
		bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() < rhs.base());
		}

	template<class L, class R>
		bool operator>(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() < rhs.base());
		}

	///	Equal or More Operator	///

	template<class Iterator> 
		bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (lhs.base() <= rhs.base());
		}

	template<class L, class R>
		bool operator>=(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
			return (lhs.base() <= rhs.base());
		}

	///		Add Operator	///

	template<class Iterator> 
		reverse_iterator<Iterator> operator+ (typename iterator_traits<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
			return (rev_it + n);
		}

	//	Substract Operator	///

	template<class Iterator> 
		typename iterator_traits<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
			return (&(*rhs.base()) - &(*(lhs.base())));
		}

		template<class L, class R>
			typename iterator_traits<L>::difference_type  operator-(const reverse_iterator<L>& lhs, const reverse_iterator<R>& rhs) {
				return (&(*rhs.base()) - &(*(lhs.base())));
			}
}
