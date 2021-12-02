#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T>
		class BST {
			public:
				typedef T value_type;
				typedef typename value_type::first_type key_type;
				typedef typename value_type::second_type mapped_type;
				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				BST(value_type p, int c = RED) : _p(p), _parent(NULL), _left(NULL), _right(NULL), _color(c) {}

				BST(BST<value_type> &other) : _p(other._p), _parent (other._parent), _left(other._left), _right(other._right), _color(other._color) {}

				///////////////////////////////////////////
				//                                       //
				//              Helpers                  //
				//                                       //
				///////////////////////////////////////////

				value_type* getPair() {
					return (&_p);
				}

				///////////////////////////////////////////
				//                                       //
				//            Extremity                  //
				//                                       //
				///////////////////////////////////////////

				BST *getMin() {
					BST* tmp = this;
					while (tmp->_left && tmp->_left->_color != GREEN)
						tmp = tmp->_left;
					return (tmp);
				}

				BST *getMax() {
					BST* tmp = this;
					while (tmp->_right && tmp->_right)
						tmp = tmp->_right;
					return (tmp);
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

				template<class Compare>
					BST* search(key_type key, Compare comp)
					{
						BST* current = this;
						while (current != NULL && (comp(current->_p.first, key) || comp(key, current->_p.first)))
						{
							if (comp(current->_p.first, key))
								current = current->_right;
							else
								current = current->_left;
						}
						return (current);
					}

				template<class Compare>
					void rec_insert(BST *n, BST* root, Compare comp) {
						if (root != NULL && root->_color != GREEN && comp(n->_p.first, root->_p.first)) {
							if (root->_left != NULL &&  root->_left->_color != GREEN) {
								rec_insert(n, root->_left, comp);
								return ;
							}
							else
							{
								n->_left = root->_left;
								root->_left = n;
							}
						}
						else if (root != NULL && root->_color != GREEN && !comp(n->_p.first, root->_p.first)) {
							if (root->_right != NULL && root->_right->_color != GREEN) {
								rec_insert(n , root->_right, comp);
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

				template<class Compare>
					void insert(BST *n, BST **root, Compare comp) {
						rec_insert(n , *root, comp);
						reorder_tree(n, root);
				}

				BST** get_child_side() {
					if (!_parent)
						return (NULL);
					if (this == _parent->_left)
						return (&_parent->_left);
					return (&_parent->_right);
				}

				void erase(BST*target, BST**root) {
					(void) root;
					BST **child_side = target->get_child_side();
					BST *tmp;
					if (!target->_left && !target->_right)
						*child_side = NULL;
					else if (target->_left && !target->_right)
					{
						target->_left->_parent = target->_parent;
						*child_side = target->_left;
					}
					else if (target->_right && !target->_left)
					{
						target->_right->_parent = target->_parent;
						*child_side = target->_right;
					}
					else if (target->_left->_color == GREEN)
					{
						tmp = target->_right;
						while (tmp->_left)
							tmp = tmp->_left;
						target->_left->_parent = tmp;
						tmp->_left = target->_left;
						*child_side = target->_right;
					}
					else if (target->_right->_color == GREEN)
					{
						tmp = target->_left;
						while (tmp->_right)
							tmp = tmp->_right;
						target->_right->_parent = tmp;
						tmp->_right = target->_right;
						*child_side = target->_left;
					}
					else
					{
						tmp = target->_right;
						while (tmp->_left)
							tmp = tmp->_left;
						if (tmp->_right && tmp != target->_right)
						{
							tmp->_parent->_left = tmp->_right;
							tmp->_right->_parent = tmp->_parent;
						}
						tmp->_parent = target->_parent;
						tmp->_left = target->_left;
						target->_left->_parent = tmp;
					}
					delete (target);
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
				value_type _p;
				BST<value_type>* _parent;
				BST<value_type>* _left;
				BST<value_type>* _right;
				int _color;
		};
}
