#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "RB_tree.hpp"
#include "RB_iterator.hpp"

namespace ft {

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {
			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////

				typedef Key key_type;
				typedef T mapped_type;
				typedef pair<const key_type, mapped_type> value_type;
				typedef Compare key_compare ;
				typedef Alloc allocator_type;
				typedef RB_tree<value_type, Compare, allocator_type> RB_tree;
				typedef RB_node<value_type, allocator_type> RB_node;
				typedef typename allocator_type::template rebind<RB_tree>::other tree_allocator_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename RB_tree::iterator iterator;
				typedef typename RB_tree::iterator const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef ptrdiff_t difference_type;
				typedef size_t size_type;
				// to complete...

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0),  _allocator(alloc), _comparator(comp){
					tree = tree_allocator.allocate(1);
					tree_allocator.construct(tree);
				}

				template<class InputIterator>
					map(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc), _comparator(comp) {
						tree = tree_allocator.allocate(1);
						tree_allocator.construct(tree);
						this->insert(first, last);
					}

				map& operator=(const map& other) {
					if (this != &other)
					{
						tree_allocator.destroy(tree);
						tree_allocator.deallocate(tree, 1);
						map::iterator first = other.begin();
						map::iterator last = other.end();
						tree = tree_allocator.allocate(1);
						tree_allocator.construct(tree);
						this->insert(first, last);
					}
					return (*this);
				}

				///////////////////////////////////////////
				//                                       //
				//             Desstructor               //
				//                                       //
				///////////////////////////////////////////

				~map() {
					tree_allocator.destroy(tree);
					tree_allocator.deallocate(tree, 1);
				}
				///////////////////////////////////////////
				//                                       //
				//              Iterators                //
				//                                       //
				///////////////////////////////////////////

				iterator begin() {
					return (iterator(tree->begin()));
				}

				const_iterator begin() const {
					return (const_iterator(tree->begin()));
				}

				iterator end() {
					return (iterator(tree->end()));
				}

				const_iterator end() const {
					return (const_iterator(tree->end()));
				}

				reverse_iterator rbegin() {
					return (reverse_iterator(tree->getMax(tree->tree)));
				}

				const_reverse_iterator rbegin() const {
					return (const_reverse_iterator(tree->getMax(tree->tree)));
				}

				reverse_iterator rend() {
					return (reverse_iterator(tree->begin()));
				}

				const_reverse_iterator rend() const {
					return (const_reverse_iterator(tree->begin()));
				}

				///////////////////////////////////////////
				//                                       //
				//           Elements access             //
				//                                       //
				///////////////////////////////////////////

				mapped_type& operator[] (const key_type& k) {
					return ((((this->insert(make_pair(k,mapped_type()))).first))->second);
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

				size_t  max_size() const {
					return (std::numeric_limits<difference_type>::max());
				}

				///////////////////////////////////////////
				//                                       //
				//              Modifiers                //
				//                                       //
				///////////////////////////////////////////

				ft::pair<iterator, bool> insert(const value_type& val) {
					ft::pair<iterator, bool> res;

					if (tree->search(val.first))
						res.second = false;
					else
						res.second = true;
					if (res.second)
						tree->insert(val, tree->tree);
					_size += res.second;
					res.first = tree->search(val.first);
					return (res);
				}

				iterator insert(iterator position, const value_type& val) {
					iterator ite = end();
					iterator tmp = position;

					if (position != ite && (_comparator(position->first, val.first) && (++tmp == ite || _comparator(val.first, tmp->first) )))
					{
						tree->insert(val, tree->search(position->first));
						_size++;
					}
					return (insert(val).first);
				}

				template<class InputIterator>
					void insert(InputIterator first, InputIterator last) {
						for (; first != last; first++)
							this->insert(*first);
					}

				void erase(iterator position) {
					
					if (!position._node)
						return ;
					tree->erase(position._node);
					_size--;
				}

				size_type erase(const key_type& k) {
					RB_node *target = tree->search(k);
					if (!target)
						return (0);
					iterator position(target);
					erase(position);
					return (1);
				}

				void erase(iterator first, iterator last) {
					iterator it = first;
					if (first != last)
						erase(++first, last);
					erase(it);
				}

				void swap(map& x) {
					RB_tree *tmp;
					int tmp_size;
					tmp = tree;
					tmp_size = _size;
					tree = x.tree;
					_size = x._size;
					x._tree = tmp;
					x._size = tmp_size;
				}

				void clear() {
					iterator first = begin();
					iterator last = end();
					erase(first, last);
				}
				void show() {
					if (tree)
						tree->show(tree->tree);
					std::cout << "-------------" << std::endl;
				}

				///////////////////////////////////////////
				//                                       //
				//              Observers                //
				//                                       //
				///////////////////////////////////////////

				key_compare key_comp() const {
					return (_comparator);
				}

				class value_compare {
					public:
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;

						value_compare (Compare c) : comp(c) {}
						bool operator() (const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
						}
					protected:
						Compare comp;
				};

				value_compare value_comp() const {
					return (value_compare(key_comp()));
				}

				///////////////////////////////////////////
				//                                       //
				//              Operations               //
				//                                       //
				///////////////////////////////////////////

				iterator find(const key_type& key) {
					RB_node* n = tree->search(key);
					if (!n)
						return (this->end());
					return (iterator(n));
				}

				const_iterator find(const key_type& key) const {
					RB_node* n = tree->search(key);
					if (!n)
						return (this->end());
					return (const_iterator(n));
				}

				size_type count (const key_type& key) const {
					if (tree->search(key))
						return (1);
					return (0);
				}

				iterator lower_bound(const key_type& key) {
					iterator it = this->begin();
					iterator ite = this->end();
					for(; it != ite; it++)
						if (!key_compare()(it->first, key))
							return (it);
					return (it);
				}

				const_iterator lower_bound(const key_type& key) const {
					const_iterator it = this->begin();
					const_iterator ite = this->end();
					for(; it != ite; it++)
						if (!key_compare()(it->first, key))
							return (it);
					return (it);
				}

				iterator upper_bound(const key_type& key) {
					iterator it = this->begin();
					iterator ite = this->end();
					for(; it != ite; it++)
						if (key_compare()(key, it->first))
							return (it);
					return (it);
				}

				const_iterator upper_bound(const key_type& key) const {
					const_iterator it = this->begin();
					const_iterator ite = this->end();
					for(; it != ite; it++)
						if (key_compare()(key, it->first))
							return (it);
					return (it);
				}

				ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
					return(ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
				}

				ft::pair<iterator, iterator> equal_range(const key_type& key) {
					return(ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
				}

				///////////////////////////////////////////
				//                                       //
				//              Allocator                //
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

	template<class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){
			if (lhs.size() != rhs.size())
				return (false);
			typename ft::map<Key,T,Compare,Alloc>::const_iterator itl = lhs.begin();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator itle = lhs.end();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator itr = rhs.begin();
			for(; itl != itle; itl++)
				if (*itl != *(itr++))
					return (false);
			return (true);
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(lhs == rhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(rhs < lhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (rhs < lhs);
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
			return (!(lhs < rhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		void swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) {
			lhs.swap(rhs);
		}
}
