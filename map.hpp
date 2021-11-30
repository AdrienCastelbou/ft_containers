#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T1, class T2>
		class BST {
			public:
				typedef T1 first_type;
				typedef T2 second_type;

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				BST(pair<first_type, second_type> p, int c = RED) : _p(p), _parent(NULL), _left(NULL), _right(NULL), _color(c) {}

				BST(BST<first_type, second_type> &other) : _p(other._p), _parent (other._parent), _left(other._left), _right(other._right), _color(other._color) {}

				///////////////////////////////////////////
				//                                       //
				//              Helpers                  //
				//                                       //
				///////////////////////////////////////////

				pair<first_type, second_type>* getPair() {
					return (&_p);
				}


				///////////////////////////////////////////
				//                                       //
				//                Family                 //
				//                                       //
				///////////////////////////////////////////

				BST *parent() const {
					return (this->_parent);
				}

				BST *leftChild() const {
					return (this->_left);
				}

				BST *rightChild() const {
					return (this->_right);
				}

				BST *grandparent() const {
					BST* parent = this->parent();
					if (parent == NULL)
						return (NULL);
					return (parent->parent());
				}

				BST *brother() const {
					BST* parent = this->parent();
					if (parent == NULL)
						return (NULL);
					if (parent->_left == this)
						return (parent->_right);
					else
						return (parent->_left);
				}

				BST *uncle() const {
					BST* parent = this->parent();
					if (parent == NULL)
						return (NULL);
					return (parent->brother());
				}

				///////////////////////////////////////////
				//                                       //
				//             Roatation                 //
				//                                       //
				///////////////////////////////////////////

				void left_rotation(BST* x, BST** root) {
					if (x->_right == NULL)
						return ;
					BST* y = x->_right;
					x->_right = y->_left;
					if (y->_left != NULL)
						y->_left->_parent = x;
					y->_parent = x->_parent;
					if (x->_parent == NULL)
						*root = y;
					else if (x == x->_parent->_left)
						x->_parent->_left = y;
					else
						x->_parent->_right = y;
					y->_left = x;
					x->_parent = y;
				}

				void right_rotation(BST* x, BST** root) {
					if (x->_left == NULL)
						return ;
					BST* y = x->_left;
					x->_left = y->_right;
					if (y->_right != NULL)
						y->_right->_parent = x;
					y->_parent = x->_parent;
					if (x->_parent == NULL)
						*root = y;
					else if (x == x->_parent->_right)
						x->_parent->_right = y;
					else
						x->_parent->_left = y;
					y->_right = x;
					x->_parent = y;
				}

				///////////////////////////////////////////
				//                                       //
				//              Operations               //
				//                                       //
				///////////////////////////////////////////

				BST* search(first_type key)
				{
					BST* current = this;
					while (current != NULL && current->_p.first != key)
					{
						if (current->_p.first < key)
							current = current->_right;
						else
							current = current->_left;
					}
					return (current);
				}

				void rec_insert(BST *n, BST* root) {
					if (root != NULL && root->_color != GREEN && n->_p.first < root->_p.first) {
						if (root->_left != NULL &&  root->_left->_color != GREEN) {
							rec_insert(n, root->_left);
							return ;
						}
						else
						{
							n->_left = root->_left;
							root->_left = n;
						}
					}
					else if (root != NULL && root->_color != GREEN && n->_p.first > root->_p.first) {
						if (root->_right != NULL && root->_right->_color != GREEN) {
							rec_insert(n , root->_right);
							return;
						}
						else
						{
							n->_right = root->_right;
							root->_right = n;
						}
					}
					else if (root != NULL && n->_p.first == root->_p.first)
						return ;
					n->_parent = root;
				}

				void reorder_case1(BST* n) {
					if (n->_parent == NULL)
						n->_color = BLACK;
				}

				void reorder_case2(BST *n) {
					(void) n;
					return ;
				}

				void reorder_case3(BST *n, BST **root) {

					n->_parent->_color = BLACK;
					n->uncle()->_color = BLACK;
					BST* grandpa = n->grandparent();
					grandpa->_color = RED;
					reorder_tree(grandpa, root);
				}

				void reorder_case4(BST *n, BST **root) {
					BST* parent = n->_parent;
					BST* grandpa = n->grandparent();

					if (grandpa && grandpa->_left && n == grandpa->_left->_right) {
						left_rotation(parent,root);
						n = n->_left;
					}
					else if (grandpa && grandpa->_right && n == grandpa->_right->_left) {
						right_rotation(parent , root);
						n = n ->_right;
					}
					reorder_case5(n , root);
				}

				void reorder_case5(BST *n, BST **root) {
					BST* parent = n->_parent;
					BST* grandpa = n->grandparent();

					if (n == parent->_left)
						right_rotation(grandpa, root);
					else
						left_rotation(grandpa, root);
					parent->_color = BLACK;
					grandpa->_color = RED;
				}

				void reorder_tree(BST* n, BST **root) {
					BST* parent = n->parent();
					BST* uncle = n->uncle();

					if (parent == NULL)
						reorder_case1(n);
					else if (parent->_color == BLACK)
						reorder_case2(n);
					else if (uncle && uncle->_color == RED)
						reorder_case3(n, root);
					else
						reorder_case4(n, root);
				}

				void insert(BST *n, BST **root) {
					rec_insert(n , *root);
					reorder_tree(n, root);
				}

				void erase(first_type key) {
					BST* current = (this->search(key));
					if (!current)
						return ;
					BST* prev= current->_parent;
					BST** branch;

					if (prev && prev->_left == current)
						branch = &prev->_left;
					else if (prev)
						branch = &prev->_right;
					if (current == this && current->_p.first != key)
						return ;
					if (this == current)
					{
						BST* left = current->_left;
						if (current->_right)
						{
							*this = *current->_right;
							current->_parent = prev;
							prev = this;
							while (prev->_left)
								prev = prev->_left;
						}
						if (current->_left)
						{
							if (current->_right)
								prev->_left = left;
							else
								*this = *left;
							left->_parent = prev;
						}
						return;
					}
					if (current->_right)
					{
						if (branch)
							*branch = current->_right;
						current->_right->_parent = prev;
						prev = current->_right;
						while (prev->_left)
							prev = prev->_left;
						branch = &prev->_left;
					}
					if (current->_left)
					{
						if (branch)
							*branch = current->_left;
						current->_left->_parent = prev;
					}
					delete current;
				}

				void set_leafs(BST* left, BST* right) {
					left->_color = GREEN;
					right->_color = GREEN;
					this->_left = left;
					this->_right = right;
				}

				void show() const {

					std::cout << _p.first << std::endl;
					if (_left && _left->_color == GREEN)
						std::cout << "left branch end" << std::endl;
					else if (_right && _right->_color == GREEN)
						std::cout << "right branch end" << std::endl;
					if (_left && _left->_color != GREEN)
						_left->show();
					std::cout << "--" << std::endl;
					if (_right && _right->_color != GREEN)
						_right->show();
/*
					if (_left && _left->_color != GREEN)
						_left->show();
					std::cout << _p.first << std::endl;
					if (_right && _right->_color != GREEN)
						_right->show();*/
				}

			private:
				pair<first_type, second_type> _p;
				BST<first_type, second_type>* _parent;
				BST<first_type, second_type>* _left;
				BST<first_type, second_type>* _right;
				int _color;
		};

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
