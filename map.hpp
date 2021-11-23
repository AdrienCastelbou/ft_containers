#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft {

	template<class T1, class T2>
		class BST {
			public:
				typedef T1 first_type;
				typedef T2 second_type;

				BST(pair<first_type, second_type> p) : _p(p), _prev(NULL), _left(NULL), _right(NULL) {}

				BST(BST<first_type, second_type> &other) : _p(other._p), _prev (other._prev), _left(other._left), _right(other._right) {}

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
							current->_left->_prev = current;
						}
						else if (current->_p.first < n._p.first && !current->_right)
						{
							current->_right = new  BST(n);
							current->_right->_prev = current;
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
					BST* prev= current->_prev;
					BST** branch;

					if (prev && prev->_left == current)
						branch = &prev->_left;
					else if (prev)
						branch = &prev->_right;
					if (current == this && current->_p.first != key)
						return ;
					*branch = NULL;
					if (this == current)
					{
						BST* left = current->_left;
						if (current->_right)
						{
							*this = *current->_right;
							current->_right->_prev = prev;
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
							left->_prev = prev;
							std::cout << this->_p.first << std::endl;
						}
						return;
					}
					if (current->_right)
					{
						*branch = current->_right;
						current->_right->_prev = prev;
						prev = current->_right;
						while (prev->_left)
							prev = prev->_left;
						branch = &prev->_left;
					}
					if (current->_left)
					{
						*branch = current->_left;
						current->_left->_prev = prev;
					}
				}

				void show() const {
					if (_left)
						_left->show();
					std::cout << _p.first << std::endl;
					if (_prev)
						std::cout << "prev of" <<  _p.first << " :" <<  _prev->_p.first << std::endl;
					if (_right)
						_right->show();
				}

			private:
				pair<first_type, second_type> _p;
				BST<first_type, second_type>* _prev;
				BST<first_type, second_type>* _left;
				BST<first_type, second_type>* _right;
		};
}
