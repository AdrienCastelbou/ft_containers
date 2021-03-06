#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "RB_node.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T, class U>
		class RB_iterator : public ft::Iterator<std::bidirectional_iterator_tag, T> {
			public:

				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////


				typedef T value_type;
				typedef U node_type;
				typedef typename ft::Iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;
				typedef typename ft::Iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;
				typedef typename ft::Iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
				typedef typename ft::Iterator<std::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
				
				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				RB_iterator(node_type *node = nullptr, node_type *last = nullptr) : _node(node), _last(last) {}

				RB_iterator(const RB_iterator& other) : _node(other._node), _last(other._last) {}

				~RB_iterator() {}

				RB_iterator& operator=(RB_iterator& other) {
					_node = other._node;
					_last = other._last;
					return (*this);
				}

				RB_iterator& operator=(const RB_iterator& other) {
					_node = other._node;
					_last = other._last;
					return (*this);
				}

				operator RB_iterator<const value_type, node_type>() {
					return (RB_iterator<const value_type, node_type>(_node, _last));
				}

				reference operator*() const {
					return (*_node->value);
				}

				pointer operator->() const {
					return (_node->value);
				}

				RB_iterator operator++() {
					if (_node == NULL)
					{
						_node = _last;
						_last = NULL;
						return (*this);
					}
					_last = _node;
					if (!this->_node->right)
					{
						while (this->_node->parent && this->_node->parent->right == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
					else 
					{
						this->_node = this->_node->right;
						while (this->_node->left)
							this->_node = this->_node->left;
					}
					return (*this);
				}

				RB_iterator operator++(int) {
					RB_iterator tmp(*this);
					operator++();
					return (tmp);
				}

				RB_iterator& operator--() {
					if (_node == NULL)
					{
						_node = _last;
						_last = NULL;
						return (*this);
					}
					_last = _node;
					if (!this->_node->left)
					{
						while (this->_node->parent && this->_node->parent->left == this->_node)
							this->_node = this->_node->parent;
						this->_node = this->_node->parent;
					}
					else 
					{
						this->_node = this->_node->left;
						while (this->_node->right)
							this->_node = this->_node->right;
					}
					return (*this);
				}

				RB_iterator operator--(int) {
					RB_iterator tmp(*this);
					operator--();
					return (tmp);
				}

				template <class Type1, class Type2, class Node>
					friend bool operator==(const RB_iterator<Type1, Node>& lhs, const RB_iterator<Type2, Node>& rhs);

				template <class Type1, class Type2, class Node>
					friend bool operator!=(const RB_iterator<Type1, Node>& lhs, const RB_iterator<Type2, Node>& rhs);

				node_type *_node;
				node_type *_last;
		};

	///////////////////////////////////////////
	//                                       //
	// BidIter Non-member function overloads //
	//                                       //
	///////////////////////////////////////////

	template<class T1, class T2, class U>
		bool operator==(const RB_iterator<T1, U>& lhs, const RB_iterator<T2, U>& rhs) {
			return (lhs._node == rhs._node);
		}

	template<class T1, class T2,  class U>
		bool operator!=(const RB_iterator<T1, U>& lhs, const RB_iterator<T2, U>& rhs) {
			return (lhs._node != rhs._node);
		}
}
