#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "BST.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T>
		class BST_iterator : public ft::Iterator<ft::bidirectional_iterator_tag, T> {
			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////


				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::reference reference;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
				typedef typename value_type::first_type key_type;
				typedef typename value_type::second_type mapped_type;
				typedef pair<key_type, mapped_type> pair_type;

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				BST_iterator(value_type *node = nullptr) : _node(node) {}

				BST_iterator(const BST_iterator& other) : _node(other._node) {}

				~BST_iterator() {}

				BST_iterator& operator=(BST_iterator& other) {
					_node = other._node;
					return (*this);
				}

				BST_iterator& operator=(const BST_iterator& other) {
					_node = other._node;
					return (*this);
				}

				pair_type operator*() {
					return (*_node->getPair());
				}

				pair_type* operator->() {
					return (_node->getPair());
				}

				BST_iterator operator++() {
					if (!this->_node->rightChild())
					{
						if (!this->_node->parent())
							return (*this);
						while (this->_node->parent() && this->_node->parent()->rightChild() == this->_node)
							this->_node = this->_node->parent();
						if (this->_node->parent())
							this->_node = this->_node->parent();
						return (*this);
					}
					this->_node = this->_node->rightChild();
					while (this->_node->leftChild())
						this->_node = this->_node->leftChild();
					return (*this);
				}

				BST_iterator operator++(int) {
					BST_iterator tmp(*this);
					operator++();
					return (tmp);
				}

				BST_iterator& operator--() {
					if (!this->_node->leftChild())
					{
						if (!this->_node->parent())
							return (*this);
						while (this->_node->parent() && this->_node->parent()->leftChild() == this->_node)
							this->_node = this->_node->parent();
						if (this->_node->parent())
							this->_node = this->_node->parent();
						return (*this);
					}
					this->_node = this->_node->leftChild();
					while (this->_node->rightChild())
						this->_node = this->_node->rightChild();
					return (*this);
				}

				BST_iterator operator--(int) {
					BST_iterator tmp(*this);
					operator--();
					return (tmp);
				}

				template <class Type>
					friend bool operator==(const BST_iterator<Type>& lhs, const BST_iterator<Type>& rhs);

				template <class Type>
					friend bool operator!=(const BST_iterator<Type>& lhs, const BST_iterator<Type>& rhs);
			protected:
				value_type *_node;
		};

	///////////////////////////////////////////
	//                                       //
	// BidIter Non-member function overloads //
	//                                       //
	///////////////////////////////////////////

	template<class T>
		bool operator==(const BST_iterator<T>& lhs, const BST_iterator<T>& rhs) {
			return (lhs._node == rhs._node);
		}

	template<class T>
		bool operator!=(const BST_iterator<T>& lhs, const BST_iterator<T>& rhs) {
			return (lhs._node != rhs._node);
		}

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
				typedef BST<key_type, mapped_type> Node;
				typedef Compare key_compare;
				//typedef value_comp value_compare;
				typedef Alloc allocator_type;
				typedef typename allocator_type::template rebind<Node>::other node_allocator_type;;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef BST_iterator<Node> iterator;
				typedef BST_iterator<const Node> const_iterator;
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
							_tree->insert(*first);
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

				pair<iterator, bool> insert(const value_type& val) {
					pair<iterator, bool> res;

					if (_tree->search(val.first))
						res.second = false;
					else
						res.second = true;
					if (_tree == NULL)
						set_root(val);
					else if (res.second)
					{
						Node* n = _node_allocator.allocate(1);
						_node_allocator.construct(n, val);
						_tree->insert(n, &_tree);
					}
					_size += res.second;
					res.first = _tree->search(val.first);
					return (res);
				}

				void show() {
					_tree->show();
				}

			private:
				BST<key_type, mapped_type> *_tree;
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
