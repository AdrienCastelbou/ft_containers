#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "BST.hpp"
#include "BST_iterator.hpp"

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
				typedef BST<value_type> Node;
				typedef Compare key_compare ;
				typedef Alloc allocator_type;
				typedef typename allocator_type::template rebind<Node>::other node_allocator_type;;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef BST_iterator<Node> iterator;
				typedef BST_iterator<const Node> const_iterator;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
				typedef size_t size_type;
				// to complete...

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0),  _allocator(alloc), _comparator(comp){
					_tree = NULL;
				}

				template<class InputIterator>
					map(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _allocator(alloc), _comparator(comp) {
						_tree = NULL;
						for(;first != last; first++)
							this->insert(*first);
					}

				///////////////////////////////////////////
				//                                       //
				//              Iterators                //
				//                                       //
				///////////////////////////////////////////

				iterator begin() {
					return (iterator(_tree->getMin()));
				}

				const_iterator begin() const {
					return (const_iterator(_tree->getMin()));
				}

				iterator end() {
					return (iterator(_tree->getMax()));
				}

				const_iterator end() const {
					return (const_iterator(_tree->getMax()));
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
					if (_tree)
						return (false);
					return (true);
				}

				size_t size() const {
					return (_size);
				}

				size_t  max_size() const {
					return (_allocator.max_size());
				}

				///////////////////////////////////////////
				//                                       //
				//              Modifiers                //
				//                                       //
				///////////////////////////////////////////

				ft::pair<iterator, bool> insert(const value_type& val) {
					ft::pair<iterator, bool> res;

					if (_tree->search(val.first, _comparator))
						res.second = false;
					else
						res.second = true;
					if (_tree == NULL)
						set_root(val);
					else if (res.second)
					{
						Node* n = _node_allocator.allocate(1);
						_node_allocator.construct(n, val);
						_tree->insert(n, &_tree, _comparator);
					}
					_size += res.second;
					res.first = _tree->search(val.first, _comparator);
					return (res);
				}

				void show() {
					_tree->show();
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
					Node* n = _tree->search(key, _comparator);
					if (!n)
						return (this->end());
					return (iterator(n));
				}

				const_iterator find(const key_type& key) const {
					Node* n = _tree->search(key, _comparator);
					if (!n)
						return (this->end());
					return (const_iterator(n));
				}

				size_type count (const key_type& key) const {
					if (_tree->search(key, _comparator))
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

				allocator_type ge_allocator() const {
					return (_allocator);
				}

			private:
				BST<value_type> *_tree;
				size_t _size;
				allocator_type _allocator;
				node_allocator_type _node_allocator;
				key_compare _comparator;

				void set_root(const value_type& val) {
					Node *left_leaf;
					Node *right_leaf;

					_tree = _node_allocator.allocate(1);
					_node_allocator.construct(_tree, val);
					left_leaf = _node_allocator.allocate(1);
					_node_allocator.construct(left_leaf, val);
					right_leaf = _node_allocator.allocate(1);
					_node_allocator.construct(right_leaf, val);
					_tree->set_leafs(left_leaf, right_leaf);
					_tree->reorder_tree(_tree, &_tree);
				}

		};

}
