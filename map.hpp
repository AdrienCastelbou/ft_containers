#pragma once

#include <iostream>
#include "utils.hpp"

namespace ft {

	template<class T1, class T2>
		class BST {
			public:
				typedef T1 first_type;
				typedef T2 second_type;

				BST(pair<first_type, second_type> p) : _p(p) {
					_prev = NULL;
					_left  = NULL;
					_right = NULL;
				}

				BST(BST<first_type, second_type> &other) : _p(other._p) {
					_prev = other._prev;
					_left  = other._left;
					_right = other._right;

				}

				void insert(BST<first_type, second_type> n) {
					BST* current = this;
					while (current != &n)
					{
						if (current->_p.first > n._p.first && !current->_left)
						{
							current->_left = new BST(n);
							n._prev = current;
						}
						else if (current->_p.first < n._p.first && !current->_right)
						{
							current->_right = new  BST(n);
							n._prev = current;
						}
						else if (current->_p.first == n._p.first)
							return ;
						if (current->_p.first > n._p.first)
							current = current->_left;
						else
							current = current->_right;
					}
				}

				void show() const {
					std::cout << _p.first << ", " << _p.second << std::endl;
					if (_left)
						_left->show();
					std::cout << "--" << std::endl;
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
