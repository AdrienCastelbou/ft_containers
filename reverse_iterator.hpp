#pragma once
#include "Iterator.hpp"

namespace ft {

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
					return (iterator_type(--it));
				}

				reference operator*() const {
					return (*(this->base()));
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
