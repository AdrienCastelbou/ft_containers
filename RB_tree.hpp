#pragma once

#include <iostream>
#include "utils.hpp"
#include "Iterator.hpp"
#include "RB_iterator.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2
namespace ft {

	template<class T, class Alloc = std::allocator<T> >
		class RB_node {
			public:
				typedef T value_type;
				typedef typename value_type::first_type key_type;
				typedef typename value_type::second_type mapped_type;
				typedef Alloc allocator_type;

				int color;
				value_type *value;
				RB_node* parent;
				RB_node* left;
				RB_node* right;
				allocator_type allocator;

				RB_node() :
					color(RED),
					value_type(),
					parent(),
					left(),
					right() {}

				RB_node(const value_type& v, RB_node* parent = NULL, RB_node* left = NULL, RB_node* right = NULL) :
					color(RED),
					parent(parent),
					left(left),
					right(right) {
						value = allocator.allocate(1);
						allocator.construct(value, v);
					}

				RB_node(const RB_node& node) :
					color(node.color),
					parent(node.parent),
					left(node.left),
					right(node.right) {
						value = allocator.allocate(1);
						allocator.construct(node.value, node.value);
					}


				~RB_node() {
					allocator.destroy(value);
					allocator.deallocate(value, 1);
				}

				RB_node& operator=(const RB_node& node) {
					if (*this == node)
						return (*this);
					color = node.color;
					value = node.value;
					parent = node.parent;
					left = node.left;
					right = node.right;
					return (*this);
				}

				bool operator==(const RB_node& node) const {
					return (value == node.value);
				}

		};

	template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
		class RB_tree {
			public:
				typedef T value_type;
				typedef Compare comparator_type;
				typedef Alloc allocator_type;
				typedef RB_node<T, allocator_type> node;
				typedef RB_node<const T, allocator_type> const_node;
				typedef typename value_type::first_type key_type;
				typedef typename allocator_type::template rebind<node>::other node_allocator_type;
				typedef RB_iterator<node> iterator;
				typedef RB_iterator<const_node> const_iterator;

				node *tree;
				allocator_type allocator;
				node_allocator_type node_allocator;
				comparator_type comp;

				RB_tree() :
					tree(NULL),
					allocator(),
					comp() {}

				RB_tree(const RB_tree &other) :
					tree(other.tree),
					allocator(other.allocator),
					comp(other.comp) {}

				~RB_tree() {
					if (tree)
						delete_node(tree);
				}

				RB_tree& operator=(const RB_tree& other) {
					if (*this == other)
						return (*this);
					tree = other.tree;
					allocator = other.allocator;
					comp = other.comp;
				}

				///////////////////////////////////////////
				//                                       //
				//            Alloc node                 //
				//                                       //
				///////////////////////////////////////////

				node *alloc_node(value_type& value) {
					node *n;
					n = node_allocator.allocate(1);
					node_allocator.construct(n, value);
					return (n);
				}

				///////////////////////////////////////////
				//                                       //
				//            Destroy node               //
				//                                       //
				///////////////////////////////////////////

				void delete_node(node *n) {
					if (n->left)
						delete_node(n->left);
					if (n->right)
						delete_node(n->right);
					node_allocator.destroy(n);
					node_allocator.deallocate(n, 1);
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
				//          Iterator Helper              //
				//                                       //
				///////////////////////////////////////////

				node *begin() {
					return (getMin(tree));
				}

				node *end() {
					return (getMax(tree));
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
						while (current != NULL && (comp(current->value->first, key) || comp(key, current->value->first)))
						{
							if (comp(current->value->first, key))
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


				node* place_and_insert(node *root, value_type value) {
					node *n = NULL;
					if (!root)
					{
						n = alloc_node(value);
						return (n);
					}
					while (root) {
						if (!comp(value.first, root->value->first) && !comp(root->value->first, value.first))
							return (n);
						else if (comp(value.first, root->value->first))
						{
							if (root->left)
								root = root->left;
							else
							{
								n = alloc_node(value);
								root->left = n;
								break;
							}
						}
						else if (comp(root->value->first, value.first))
						{
							if (root->right)
								root = root->right;
							else
							{
								n = alloc_node(value);
								root->right = n;
								break;
							}
						}
					}
					n->parent = root;
					return (n);
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

				void insert(value_type val, node *root) {
					node *n = place_and_insert(root, val);
					if (n == NULL)
						return ;
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
					if (n == NULL)
						return (n);
					while (n->left)
						n = n->left;
					return (n);
				}

				node* getMax(node *n) {
					if (n == NULL)
						return (n);
					while (n->right)
						n = n->right;
					return (n);
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
							if (isOnLeft(bro))
								right_rotation(parent);
							else
								left_rotation(parent);
							fixDoubleBlack(n);
						}
						else { // bro is black
							if ((bro->left && bro->left->color == RED) || (bro->right && bro->right->color == RED)) { // 1+ Red child
								if (bro->right && bro->right->color == RED) { // Red child is right child
									if (isOnLeft(bro)) {
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
									if (isOnLeft(bro)) {
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

				void show_node(node *n) {
					std::cout << "         NODE" <<std::endl;
					std::cout << "VALUE : " << n->value->first << std::endl;
					std::cout << "COLOR : " << n->color << std::endl;
					std::cout << "PARENT : " ;
					if (n->parent)
					{
						std::cout << n->parent->value->first << ", LEFT : " ;
						if (n->parent->left)
							std::cout << n->parent->left->value->first ;
						else
							std::cout << "no left";
						if (n->parent->right)
							std::cout << ", RIGHT : " << n->parent->right->value->first << std::endl;
						else
							std::cout << "no right" << std::endl;
					}
					else
						std::cout << "no parent" << std::endl;
					std::cout << "LEFT : ";
					if (n->left)
						std::cout << n->left->value->first << std::endl;
					else
						std::cout << "no left" << std::endl;
					std::cout << "RIGHT : ";
					if (n->right)
						std::cout << n->right->value->first << std::endl;
					else
						std::cout << "no right" << std::endl;

					std::cout << "--------------" << std::endl;
				}

				void swapValues(node *v, node *u) {
					node *u_parent = u->parent;
					bool u_isOnLeft = isOnLeft(u);
					node *u_left = u->left;
					node *u_right = u->right;
					int u_color = u->color;
					
					std::cout << "V" << std::endl;
					show_node(v);
					std::cout << "U" << std::endl;
					show_node (u);
					/*value_type *tmp;
					tmp = u->value;
					u->value = v->value;
					v->value = tmp;*/
					u->parent = v->parent;
					if (isOnLeft(v) && u->parent)
						u->parent->left = u;
					else if (u->parent)
						u->parent->right = u;
					u->left = v->left;
					u->right = v->right;
					u->color = v->color;

					v->parent = u_parent;
					if (u_isOnLeft && v->parent)
						v->parent->left = v;
					else if (v->parent)
						v->parent->right = v;
					v->left = u_left;
					v->right = u_right;
					v->color = u_color;
					std::cout << "NEW V" << std::endl;
					show_node(v);
					std::cout << "NEW U" << std::endl;
					show_node (u);
				}


				void erase(node *v, iterator first) {
					node *u = nodeReplace(v);
					node *parent = v->parent;
					bool uvBlack = ((u == NULL || u->color == BLACK) && v->color == BLACK);
					if (u == NULL) // when v is leaf and has no children
					{
						if (v == tree)
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
						node_allocator.destroy(v);
						node_allocator.deallocate(v, 1);
						return ;
					}
					if (v->left == NULL || v->right == NULL) { // v has 1 child
						if (v == tree) {
							u->parent = NULL;
							tree = u;
							v->left = NULL;
							v->right = NULL;
							node_allocator.destroy(v);
							node_allocator.deallocate(v, 1);
						}
						else {
							if (isOnLeft(v)) // detach v from tree, replace it by u
								parent->left = u;
							else
								parent->right = u;
							node_allocator.destroy(v);
							node_allocator.deallocate(v, 1);
							u->parent = parent;
							if (uvBlack) // if v and u are black
								fixDoubleBlack(u);
							else // u or v red, color u black
								u->color = BLACK;
						}
						return ;
					}
					// v has 2 children, swap and recurse
					
					swapValues(v, u);
					erase(v, first);
				}

				///////////////////////////////////////////
				//                                       //
				//                 Utils                 //
				//                                       //
				///////////////////////////////////////////
				
				void show(node *node) const {
					if (!node)
						return ;
					std::cout << node->value->first << ", " << node->color << std::endl;
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
}
