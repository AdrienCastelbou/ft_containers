#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "RB_tree.hpp"
#include "RB_iterator.hpp"

namespace ft {
	template<class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
		class set {
			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////

				typedef T key_type;
				typedef T value_type;
				typedef Compare key_compare;
				typedef Compare value_compare;
				typedef Alloc allocator_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef RB_tree<key_type, value_type, Identity<value_type>, key_compare, allocator_type> RB_tree;
				typedef RB_node<value_type, allocator_type> RB_node;
				typedef typename allocator_type::template rebind<RB_tree>::other tree_allocator_type;
				typedef typename RB_tree::const_iterator iterator;
				typedef typename RB_tree::const_iterator const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef ptrdiff_t difference_type;
				typedef size_t size_type;

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc), _comparator(comp) {
					tree = tree_allocator.allocate(1);
					tree_allocator.construct(tree);
				}

				template<class InputIterator>
					set(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc), _comparator(comp) {
					tree = tree_allocator.allocate(1);
					tree_allocator.construct(tree);
					insert(first, last);
				}

				set(const set& x) : _size(0), _allocator(x._allocator), _comparator(x._comparator) {
					tree = tree_allocator.allocate(1);
					tree_allocator.construct(tree);
					insert(x.begin(), x.end());
				}

				set& operator=(const set& other) {
					if (this != &other) {
						clear();
						insert(other.begin(), other.end());
					}
					return (*this);
				}

				///////////////////////////////////////////
				//                                       //
				//               Destructor              //
				//                                       //
				///////////////////////////////////////////

				~set() {
					tree_allocator.destroy(tree);
					tree_allocator.deallocate(tree, 1);
				}

				///////////////////////////////////////////
				//                                       //
				//               Iterators               //
				//                                       //
				///////////////////////////////////////////

				iterator begin() {
					return (iterator(tree->begin()));
				}

				const_iterator begin() const {
					return (const_iterator(tree->begin()));
				}

				iterator end() {
					return (iterator(NULL, tree->end()));
				}

				const_iterator end() const {
					return (const_iterator(NULL, tree->end()));
				}

				reverse_iterator rbegin() {
					iterator it(NULL, tree->end());
					return (reverse_iterator(it));
				}

				const_reverse_iterator rbegin() const {
					const_iterator it(NULL, tree->end());
					return (const_reverse_iterator(it));
				}

				reverse_iterator rend() {
					iterator it(tree->begin());
					return (reverse_iterator(it));
				}

				const_reverse_iterator rend() const {
					const_iterator it(tree->begin());
					return (const_reverse_iterator(it));
				}

				///////////////////////////////////////////
				//                                       //
				//               Capacity                //
				//                                       //
				///////////////////////////////////////////

				bool empty() const {
					if (_size == 0)
						return (true);
					return (false);
				}

				size_type size() const {
					return (_size);
				}

				size_type max_size() const {
					return (tree->max_size());
				}

				///////////////////////////////////////////
				//                                       //
				//              Modifiers                //
				//                                       //
				///////////////////////////////////////////


				ft::pair<iterator, bool> insert(const value_type& val) {
					ft::pair<iterator, bool> res;
					if (tree->search(val))
						res.second = false;
					else
						res.second = true;
					if (res.second)
						tree->insert(val, tree->tree);
					_size += res.second;
					res.first = tree->search(val);
					return (res);
				}

				iterator insert(iterator position, const value_type& val) {
					iterator ite = end();
					iterator tmp = position;

					if (position != ite && (_comparator(*position, val) && (++tmp == ite || _comparator(val, *tmp))))
					{
						tree->insert(val, tree->search(*position));
						_size++;
					}
					return (insert(val).first);
				}

				template<class InputIterator>
					void insert(InputIterator first, InputIterator last) {
						for(; first != last; first++)
							this->insert(*first);
					}

				void erase(iterator position) {
					if (!position._node || !tree->search(*position))
						return;
					tree->erase(position._node);
					_size--;
				}

				size_type erase(const value_type& val) {
					RB_node *target = tree->search(val);
					if (!target)
						return (0);
					tree->erase(target);
					_size--;
					return (1);
				}

				void erase(iterator first, iterator last) {
					while (first != last)
						erase(*(first++));
				}

				void swap(set& x) {
					RB_tree *tmp;
					size_type tmp_size;
					tmp = tree;
					tmp_size = _size;
					tree = x.tree;
					_size = x._size;
					x.tree = tmp;
					x._size = tmp_size;
				}

				void clear() {
					erase(begin(), end());
				}

				///////////////////////////////////////////
				//                                       //
				//              Observers                //
				//                                       //
				///////////////////////////////////////////

				key_compare key_comp() const {
					return (_comparator);
				}

				value_compare value_comp() const {
					return (_comparator);
				}

				///////////////////////////////////////////
				//                                       //
				//              Operations               //
				//                                       //
				///////////////////////////////////////////

				iterator find(const key_type& key) const {
					RB_node* n = tree->search(key);
					if (!n)
						return (end());
					return (iterator(n));
				}

				size_type count (const key_type& key) const {
					if (tree->search(key))
						return(1);
					return (0);
				}

				iterator lower_bound(const key_type& key) const {
					return (tree->lower_bound(key));
				}

				iterator upper_bound(const key_type& key) const {
					return (tree->upper_bound(key));
				}

				ft::pair<iterator, iterator> equal_range(const key_type& key) const {
					return (ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
				}

				///////////////////////////////////////////
				//                                       //
				//               Allocator               //
				//                                       //
				///////////////////////////////////////////

				allocator_type get_allocator() const {
					return (_allocator);
				}

			private:
				RB_tree *tree;
				size_t _size;
				allocator_type _allocator;
				tree_allocator_type tree_allocator;
				key_compare _comparator;
		};

				///////////////////////////////////////////
				//                                       //
				//     Non-member function overloads     //
				//                                       //
				///////////////////////////////////////////

	template< class T, class Compare, class Alloc >
		bool operator==( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ){
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::set<T,Compare,Alloc>::const_iterator itl = lhs.begin();
			typename ft::set<T,Compare,Alloc>::const_iterator itle = lhs.end();
			typename ft::set<T,Compare,Alloc>::const_iterator itr = rhs.begin();
			for(; itl != itle; itl++)
				if (*itl != *(itr++))
					return (false);
			return (true);
		}

	template<  class T, class Compare, class Alloc >
		bool operator!=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (!(lhs == rhs));
		}

	template<  class T, class Compare, class Alloc >
		bool operator<( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template<  class T, class Compare, class Alloc >
		bool operator<=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (!(rhs < lhs));
		}

	template<  class T, class Compare, class Alloc >
		bool operator>( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (rhs < lhs);
		}

	template<  class T, class Compare, class Alloc >
		bool operator>=( const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs ) {
			return (!(lhs < rhs));
		}

	template<class T, class Compare, class Alloc >
		void swap(ft::set<T,Compare,Alloc>& lhs, ft::set<T,Compare,Alloc>& rhs ) {
			lhs.swap(rhs);
		}

}
