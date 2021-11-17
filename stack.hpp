#pragma once
#include "vector.hpp"
#include "Iterator.hpp"

namespace ft {

	template<class T, class Container = ft::vector<T> >
		class stack {
			public:
				///////////////////////////////////////////
				//                                       //
				//             Member types              //
				//                                       //
				///////////////////////////////////////////
				
				typedef Container container_type;
				typedef typename Container::value_type value_type;
				typedef typename Container::size_type size_type;

				///////////////////////////////////////////
				//                                       //
				//              Constructors             //
				//                                       //
				///////////////////////////////////////////

				explicit stack(const container_type& cont = container_type()) : c(cont) {}

				stack(const stack& other) {
					c = other.c;
				}

				stack& operator=(const stack& other) {
					c = other.c;
					return (*this);
				}
				///////////////////////////////////////////
				//                                       //
				//              Destructor               //
				//                                       //
				///////////////////////////////////////////

				~stack() {}

				///////////////////////////////////////////
				//                                       //
				//               Capacity                //
				//                                       //
				///////////////////////////////////////////

				bool empty() const {
					return (c.empty());
				}

				size_type size() const {
					return (c.size());
				}

				///////////////////////////////////////////
				//                                       //
				//            Element access             //
				//                                       //
				///////////////////////////////////////////

				value_type& top() {
					return (c.back());
				}

				const value_type& top() const {
					return (c.back());
				}

				///////////////////////////////////////////
				//                                       //
				//              Modifiers                //
				//                                       //
				///////////////////////////////////////////

				void push(const value_type& val) {
					c.push_back(val);
				}

				void pop() {
					c.pop_back();
				}

				///////////////////////////////////////////
				//                                       //
				// Friends Non-member function overloads //
				//                                       //
				///////////////////////////////////////////

	template <class Type, class Container_type>
		friend bool operator== (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

	template <class Type, class Container_type>
		friend bool operator!= (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

	template <class Type, class Container_type>
		friend bool operator< (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

	template <class Type, class Container_type>
		friend bool operator<= (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

	template <class Type, class Container_type>
		friend bool operator> (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

	template <class Type, class Container_type>
		friend bool operator>= (const stack<Type, Container_type>& lhs, const stack<Type, Container_type>& rhs);

			protected:
				container_type c;
		};

				///////////////////////////////////////////
				//                                       //
				//     Non-member function overloads     //
				//                                       //
				///////////////////////////////////////////

	template <class T, class Container>
		bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs.c == rhs.c);
		}

	template <class T, class Container>
		bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
			return (lhs.c != rhs.c);
		}

	template <class Type, class Container_type>
		bool operator< (const ft::stack<Type, Container_type>& lhs, const ft::stack<Type, Container_type>& rhs) {
			return (lhs.c < rhs.c);
		}

	template <class Type, class Container_type>
		bool operator<= (const ft::stack<Type, Container_type>& lhs, const ft::stack<Type, Container_type>& rhs) {
			return (lhs.c <= rhs.c);
		}

	template <class Type, class Container_type>
		bool operator> (const ft::stack<Type, Container_type>& lhs, const ft::stack<Type, Container_type>& rhs) {
			return (lhs.c > rhs.c);
		}

	template <class Type, class Container_type>
		bool operator>= (const ft::stack<Type, Container_type>& lhs, const ft::stack<Type, Container_type>& rhs) {
			return (lhs.c >= rhs.c);
		}
}
