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
				typedef typename RB_tree::iterator iterator;
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
					set(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc), _comparator(comp) {
					tree = tree_allocator.allocate(1);
					tree_allocator.construct(tree);
					(void)first;
					(void) last;
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

			private:
				RB_tree *tree;
				size_t _size;
				allocator_type _allocator;
				tree_allocator_type tree_allocator;
				key_compare _comparator;
		};
}
