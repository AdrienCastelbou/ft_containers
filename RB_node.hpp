#pragma once

#include "utils.hpp"
#define BLACK 0
#define RED 1
#define GREEN 2

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
		class RB_node {
			public:
				typedef T value_type;
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

}
