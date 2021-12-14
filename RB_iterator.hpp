#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "RB_tree.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T>
		class RB_iterator : public ft::Iterator<ft::bidirectional_iterator_tag, T> {
			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////


				typedef T node_type;
				typedef typename node_type::value_type value_type;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
				typedef typename ft::Iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				RB_iterator(node_type *node = nullptr) : _node(node) {}

				RB_iterator(const RB_iterator& other) : _node(other._node) {}

				~RB_iterator() {}

				RB_iterator& operator=(RB_iterator& other) {
					_node = other._node;
					return (*this);
				}

				RB_iterator& operator=(const RB_iterator& other) {
					_node = other._node;
					return (*this);
				}

				operator RB_iterator<const T>() {
					return (RB_iterator<const T>(_node));
				}

				reference operator*() {
					return (*_node->value);
				}

				pointer operator->() {
					return (_node->value);
				}

				RB_iterator operator++() {
					if (!this->_node->right)
					{
						while (this->_node->parent && this->_node->parent->right == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
						return (*this);
					}
					this->_node = this->_node->right;
					while (this->_node->left)
						this->_node = this->_node->left;
					return (*this);
				}

				RB_iterator operator++(int) {
					RB_iterator tmp(*this);
					operator++();
					return (tmp);
				}

				RB_iterator& operator--() {
					if (!this->_node->left)
					{
						while (this->_node->parent && this->_node->parent->left == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
						return (*this);
					}
					this->_node = this->_node->left;
					while (this->_node->right)
						this->_node = this->_node->right;
					return (*this);
				}

				RB_iterator operator--(int) {
					RB_iterator tmp(*this);
					operator--();
					return (tmp);
				}

				template <class Type>
					friend bool operator==(const RB_iterator<Type>& lhs, const RB_iterator<Type>& rhs);

				template <class Type>
					friend bool operator!=(const RB_iterator<Type>& lhs, const RB_iterator<Type>& rhs);

				node_type *_node;
		};

	///////////////////////////////////////////
	//                                       //
	// BidIter Non-member function overloads //
	//                                       //
	///////////////////////////////////////////

	template<class T>
		bool operator==(const RB_iterator<T>& lhs, const RB_iterator<T>& rhs) {
			return (lhs._node == rhs._node);
		}

	template<class T>
		bool operator!=(const RB_iterator<T>& lhs, const RB_iterator<T>& rhs) {
			return (lhs._node != rhs._node);
		}
}
