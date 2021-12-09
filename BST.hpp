#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T>
		class BST_node {
			public:
				typedef T value_type;

				int color;
				value_type value;
				BST_node* parent;
				BST_node* left;
				BST_node* right;

				BST_node() :
					color(RED),
					value_type(),
					parent(),
					left(),
					right() {}

				BST_node(const value_type& v, BST_node* parent = NULL, BST_node* left = NULL, BST_node* right = NULL) :
					color(RED),
					value(v),
					parent(parent),
					left(left),
					right(right) {}

				BST_node(const BST_node& node) :
					color(node.color),
					value(node.value),
					parent(node.parent),
					left(node.left),
					right(node.right) {}

				~BST_node() {}

				BST_node& operator=(const BST_node& node) {
					if (*this == node)
						return (*this);
					color = node.color;
					value = node.value;
					parent = node.parent;
					left = node.left;
					right = node.right;
					return (*this);
				}

				bool operator==(const BST_node& node) const {
					return (value == node.value);
				}

		};

	template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
		class BST_tree {
			public:
				typedef T value_type;
				typedef BST_node<T> node;
				typedef typename value_type::first_type key_type;
				typedef Compare comparator_type;
				typedef Alloc allocator_type;

				node *tree;
				allocator_type allocator;
				comparator_type comp;

				BST_tree() :
					tree(NULL),
					allocator(),
					comp() {}

				BST_tree(const BST_tree &other) :
					tree(other.tree),
					allocator(other.allocator),
					comp(other.comp) {}

				~BST_tree() {}

				BST_tree& operator=(const BST_tree& other) {
					if (*this == other)
						return (*this);
					tree = other.tree;
					allocator = other.allocator;
					comp = other.comp;
				}

				///////////////////////////////////////////
				//                                       //
				//                Family                 //
				//                                       //
				///////////////////////////////////////////

				node* parent(node* n) {
					return (n->parent);
				}

				node* grandparent(node* n) {
					node* p = parent(n);
					if (p == NULL)
						return (NULL);
					return (parent(p));
				}

				node* brother(node* n) {
					node* p = parent(n);
					if (p == NULL)
						return (NULL);
					if (n == p->left)
						return (p->right);
					else
						return (p->left);
				}

				node* uncle(node *n) {
					node* p = parent(n);
					node* g = grandparent(n);
					if (g == NULL)
						return (NULL);
					return (brother(p));
				}

				///////////////////////////////////////////
				//                                       //
				//             Rotations                 //
				//                                       //
				///////////////////////////////////////////

				void left_rotation(node *n) {
					node *y = n->right;
					n->right = y->left;
					if (y->left)
						y->left->parent = n;
					y->parent = n->parent;
					if (n->parent == NULL)
						tree = y;
					else if (n == n->parent->left)
						n->parent->left = y;
					else
						n->parent->right = y;
					y->left = n;
					n->parent = y;
				}

				void right_rotation(node *n) {
					node *y = n->left;
					n->left = y->right;
					if (y->right)
						y->right->parent = n;
					y->parent = n->parent;
					if (n->parent == NULL)
						tree = y;
					else if (n == n->parent->right)
						n->parent->right = y;
					else
						n->parent->left = y;
					y->right = n;
					n->parent = y;
				}
				///////////////////////////////////////////
				//                                       //
				//               Search                  //
				//                                       //
				///////////////////////////////////////////

				node* search(key_type key){
						node *current = tree;
						while (current != NULL && (comp(current->value.first, key) || comp(key, current->value.first)))
						{
							if (comp(current->value.first, key))
								current = current->right;
							else
								current = current->left;
						}
						return (current);
					}


				///////////////////////////////////////////
				//                                       //
				//             Insertion                 //
				//                                       //
				///////////////////////////////////////////

				void rec_insert(node *root, node *n) {
					if (root && !comp(n->value.first, root->value.first) && !comp(root->value.first, n->value.first))
						return ;
					if (root && comp(n->value.first, root->value.first))
					{
						if (root->left)
						{
							rec_insert(root->left, n);
							return ;
						}
						else
							root->left = n;
					}
					else if (root)
					{
						if (root->right)
						{
							rec_insert(root->right, n);
							return ;
						}
						else
							root->right = n;
					}
					n->parent = root;
					n->left = NULL;
					n->right = NULL;
				}

				void insert_case1(node* n) {
					if (parent(n) == NULL)
						n->color = BLACK;
				}

				void insert_case2(node* n) {
					(void) n;
					return ;
				}

				void insert_case3(node *n) {
					parent(n)->color = BLACK;
					uncle(n)->color = BLACK;
					node *g = grandparent(n);
					g->color = RED;
					balance_tree(g);
				}

				void insert_case4(node *n) {
					node *p = parent(n);
					node *g = grandparent(n);
					if (g->left && n == g->left->right)
					{
						left_rotation(p);
						n = n->left;
					}
					else if (g->right && n == g->right->left)
					{
						right_rotation(p);
						n = n->right;
					}
					insert_case5(n);
				}

				void insert_case5(node *n) {
					node *p = parent(n);
					node *g = grandparent(n);

					if (n == p->left)
						right_rotation(g);
					else
						left_rotation(g);
					p->color = BLACK;
					g->color = RED;
				}

				void balance_tree(node *n) {
					if (n == NULL)
						return ;
					if (parent(n) == NULL)
						insert_case1(n);
					else if (parent(n)->color == BLACK)
						insert_case2(n);
					else if (uncle(n) && uncle(n)->color == RED)
						insert_case3(n);
					else
						insert_case4(n);
				}

				void insert(node *n) {
					rec_insert(tree, n);
					balance_tree(n);
					tree = n;
					while (parent(tree) != NULL)
						tree = parent(tree);
				}

				///////////////////////////////////////////
				//                                       //
				//                 Erase                 //
				//                                       //
				///////////////////////////////////////////

				node* getMin(node *n) {
					while (n->left)
						n = n->left;
					return (n);
				}

				node* rec_erase(node *root, key_type key) {
					if (root == NULL)
						return (root);
					if (comp(key, root->value.first))
						root->left = rec_erase(root->left, key);
					else if (comp(root->value.first, key))
						root->right = rec_erase(root->right, key);
					else {
						if (root->left == NULL && root->right == NULL)
						{
							delete root;
							return (NULL);
						}
						else if (root->left == NULL)
						{
							node *tmp = root->right;
							delete root;
							return (tmp);
						}
						else if (root->right == NULL)
						{
							node *tmp = root->left;
							delete root;
							return (tmp);
						}
						node *tmp = getMin(root->right);
						root->value = tmp->value;
						root->right = rec_erase(root->right, tmp->value.first);
					}
					return (root);
				}

				node *nodeReplace(node *n) {
					if (n->left && n->right)
						return (getMin(n->right));
					if (n->left == NULL && n->right == NULL)
						return (NULL);
					if (n->left)
						return (n->left);
					else
						return (n->right);
				}

				void swapValues(node *u, node *v) {
					value_type tmp;
					tmp = u->value;
					u->value = v->value;
					v->value = tmp;
				}

				bool isOnLeft(node *n) {
					return (n->parent && n->parent->left == n);
				}
				void fixDoubleBlack(node *n) {
					if (n == tree)
						return ;
					node *bro = brother(n);
					node *parent = n->parent;
					if (bro == NULL) // no brother, double black pushed up
						fixDoubleBlack(parent);
					else {
						if (bro->color == RED) { // if bro is red
							parent->color = RED;
							bro->color = BLACK;
							if (parent && parent->left == bro)
								right_rotation(parent);
							else
								left_rotation(parent);
							fixDoubleBlack(n);
						}
						else { // bro is black
							if ((bro->left && bro->left->color == RED) || (bro->right && bro->right->color == RED)) { // 1+ Red child
								if (bro->right && bro->right->color == RED) { // Red child is right child
									if (bro->parent->left == bro) {
										bro->right->color = parent->color;
										left_rotation(bro);
										right_rotation(parent);
									}
									else {
										bro->right->color = bro->color;
										bro->color = parent->color;
										left_rotation(parent);
									}
								}
								else { // Red child is left child
									if (bro->parent->left == bro) {
										bro->left->color = bro->color;
										bro->color = parent->color;
										right_rotation(parent);
									}
									else {
										bro->left->color = parent->color;
										right_rotation(bro);
										left_rotation(parent);
									}
								}
								parent->color = BLACK;
							}
							else { // Two black children
								bro->color = RED;
								if (parent->color == BLACK)
									fixDoubleBlack(parent);
								else
									parent->color = BLACK;
							}
						}
					}
				}

				void erase(node *v) {
					node *u = nodeReplace(v);
					node *parent = v->parent;
					bool uvBlack = ((u == NULL || u->color == BLACK) && v->color == BLACK);
					if (u == NULL) // when v is leaf and has no children
					{
						if (u == tree)
							tree = NULL;
						else
						{
							if (uvBlack) // if v is black (u is also black because NULL)
								fixDoubleBlack(v);
							else if (brother(v)) // u or v is red
								brother(v)->color = RED;
							if (isOnLeft(v))
								parent->left = NULL;
							else if (parent)
								parent->right = NULL;
						}
						delete v;
						return ;
					}
					if (v->left == NULL || v->right == NULL) { // v has 1 child
						if (v == tree) {
							v->value = u->value;
							v->left = NULL;
							v->right = NULL;
							delete u;
						}
						else {
							if (isOnLeft(v)) // detach v from tree, replace it by u
								parent->left = u;
							else
								parent->right = u;
							delete v;
							u->parent = parent;
							if (uvBlack) // if v and u are black
								fixDoubleBlack(u);
							else // u or v red, color u black
								u->color = BLACK;
						}
						return ;
					}
					// v has 2 children, swap and recurse
					swapValues(u, v);
					erase(u);
					//tree = rec_erase(tree, key);
				}

				///////////////////////////////////////////
				//                                       //
				//                 Utils                 //
				//                                       //
				///////////////////////////////////////////
				
				void show(node *node) const {
					if (!node)
						return ;
					std::cout << node->value.first << ", " << node->color << std::endl;
					if (!node->left)
						std::cout << "left branch end" << std::endl;
					if (!node->right)
						std::cout << "right branch end" << std::endl;
					if (node->left)
						show(node->left);
					std::cout << "--" << std::endl;
					if (node->right)
						show(node->right);
				}
		};

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
						//reorder_tree(n, root);
				}

				BST** get_child_side(BST **root) {
					if (!_parent)
						return (root);
					if (this == _parent->_left)
						return (&_parent->_left);
					return (&_parent->_right);
				}


				void erase(BST*target, BST**root) {
					BST **child_side = target->get_child_side(root);
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
					else if (target->_left->_color == GREEN && target->_right->_color == GREEN)
					{
						delete (target->_left);
						delete(target->_right);
						*root = NULL;
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
						tmp->_left = target->_left;
						target->_left->_parent = tmp;
						if (target->_right != tmp)
						{
							tmp->_parent->_left = tmp->_right;
							if (tmp->_right)
								tmp->_right->_parent = tmp->_parent;
						}
						tmp->_right = target->_right;
						target->_right->_parent = tmp;
						*child_side = tmp;
						tmp->_parent = target->_parent;
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

					std::cout << _p.first << ", " << _color << std::endl;
					if (_left && _left->_color == GREEN)
						std::cout << "left branch end" << std::endl;
					if (_right && _right->_color == GREEN)
						std::cout << "right branch end" << std::endl;
					if (_left && _left->_color != GREEN)
						_left->show();
					std::cout << "--" << std::endl;
					if (_right && _right->_color != GREEN)
						_right->show();
				}

			private:
				value_type _p;
				BST<value_type>* _parent;
				BST<value_type>* _left;
				BST<value_type>* _right;
				int _color;
		};

}
