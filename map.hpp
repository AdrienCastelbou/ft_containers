#pragma once

#include <iostream>
#include "utils.hpp"

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

				BST(pair<first_type, second_type> p) : _p(p), _parent(NULL), _left(NULL), _right(NULL), _key(1) {}

				BST(BST<first_type, second_type> &other) : _p(other._p), _parent (other._parent), _left(other._left), _right(other._right), _key(other._key) {}

				///////////////////////////////////////////
				//                                       //
				//              Helpers                  //
				//                                       //
				///////////////////////////////////////////

				///////////////////////////////////////////
				//                                       //
				//                Family                 //
				//                                       //
				///////////////////////////////////////////

				BST *parent() const {
					return (this->_parent);
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
					BST* grandparent = this->grandparent();
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

				BST& search(first_type key)
				{
					BST* current = this;
					while (current != NULL && current->_p.first != key)
					{
						if (current->_p.first < key)
							current = current->_right;
						else
							current = current->_left;
					}
					if (!current)
						return (*this);
					return (*current);
				}

				void insert(BST<first_type, second_type> n) {
					BST* current = this;
					while (current != NULL)
					{
						if (current->_p.first > n._p.first && !current->_left)
						{
							current->_left = new BST(n);
							current->_left->_parent = current;
						}
						else if (current->_p.first < n._p.first && !current->_right)
						{
							current->_right = new  BST(n);
							current->_right->_parent = current;
						}
						else if (current->_p.first == n._p.first)
							return ;
						if (current->_p.first > n._p.first)
							current = current->_left;
						else
							current = current->_right;
					}
				}

				void erase(first_type key) {
					BST* current = &(this->search(key));
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

				void show() const {
					std::cout << _p.first << std::endl;
					if (_left)
						_left->show();
					std::cout << "--" << std::endl;
					if (_right)
						_right->show();

					/*if (_left)
						_left->show();
					std::cout << _p.first << std::endl;
					if (_right)
						_right->show();*/
				}

			private:
				pair<first_type, second_type> _p;
				BST<first_type, second_type>* _parent;
				BST<first_type, second_type>* _left;
				BST<first_type, second_type>* _right;
				int _key;
		};
}
