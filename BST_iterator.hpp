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
				typedef typename value_type::key_type key_type;
				typedef typename value_type::mapped_type mapped_type;
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

				operator BST_iterator<const T>() {
					return (BST_iterator<const T>(_node));
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

}
