#pragma once
#include <iostream>
#include <vector>

namespace ft {

	template<typename _Arg, typename _Result>
		class unary_function {
			public:
				typedef _Arg argument_type;
				typedef _Result result_type;
		};

	template<typename _Pair>
		class Select_first : public unary_function<_Pair, typename _Pair::first_type> {
			public:
				typename _Pair::first_type& operator() (_Pair& x) const {
					return (x.first);
				}

				const typename _Pair::first_type& operator() (const _Pair& x) const {
					return (x.first);
				}
		};

	template<typename _Pair>
		class Select_scnd : public unary_function<_Pair, typename _Pair::second_type> {
			public:
				typename _Pair::second_type& operator() (_Pair& x) const {
					return (x.second_type);
				}

				const typename _Pair::second_type& operator() (const _Pair& x) {
					return (x.second_type);
				}
		};

	template<typename T>
		class Identity : public unary_function<T, T> {
			T& operator() (T& x) const {
				return (x);
			}
			const T& operator() (const T& x) const {
				return (x);
			}
		};

				///////////////////////////////////////////
				//                                       //
				//                 Pair                  //
				//                                       //
				///////////////////////////////////////////

	template<class T1, class T2>
		class pair {
			public:
				typedef T1 first_type;
				typedef T2 second_type;

				first_type first;
				second_type second;

				///////////////////////////////////////////
				//                                       //
				//             Constructors              //
				//                                       //
				///////////////////////////////////////////

				pair() : first(), second() {}
				template<class U, class V>
					pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
				pair(const first_type& a, const second_type& b) : first(a), second(b) {}

				template<class U, class V>
					pair& operator=(const pair<U, V>& pr) {
						first = pr.first;
						second = pr.second;
						return (*this);
					}
		};

	///////////////////////////////////////////
	//                                       //
	//   Pair Non-member function overloads  //
	//                                       //
	///////////////////////////////////////////

	template <class T1, class T2>
		bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}

	template <class T1, class T2>
		bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (!(lhs==rhs));
		}

	template <class T1, class T2>
		bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
		}

	template <class T1, class T2>
		bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (!(rhs<lhs));
		}

	template <class T1, class T2>
		bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (rhs<lhs);
		}

	template <class T1, class T2>
		bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) {
			return (!(lhs<rhs));
		}

	///////////////////////////////////////////
	//                                       //
	//               Make Pair               //
	//                                       //
	///////////////////////////////////////////

	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y) {
			return ( pair<T1,T2>(x,y) );
		}

	///////////////////////////////////////////
	//                                       //
	//        Lexicographical compare        //
	//                                       //
	///////////////////////////////////////////

	template<class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
			while (first1 != last1)
			{
				if (first2 == last2 || *first2 < *first1)
					return (false);
				else if (*first1 < *first2)
					return (true);
				++first1;
				++first2;
			}
			return (first2!=last2);
		}

	template<class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
			while (first1 != last1)
			{
				if (first2 == last2 || comp(*first2, *first1))
					return (false);
				else if (comp(*first1, *first2))
					return (true);
				++first1;
				++first2;
			}
			return (first2!=last2);
		}

	///////////////////////////////////////////
	//                                       //
	//              Is_integral              //
	//                                       //
	///////////////////////////////////////////


	template<bool Cond, class T>
		class set_is_integral {
			public:
				typedef T type;
				static const bool value = Cond;
		};

	template<typename>
		class is_integral_type : public set_is_integral<false, bool>{};

	template<>
		class is_integral_type<bool> : public set_is_integral<true, bool>{};

	template<>
		class is_integral_type<char> : public set_is_integral<true, char>{};

	template<>
		class is_integral_type<char16_t> : public set_is_integral<true, char16_t>{};

	template<>
		class is_integral_type<char32_t> : public set_is_integral<true, char32_t>{};

	template<>
		class is_integral_type<wchar_t> : public set_is_integral<true, wchar_t>{};

	template<>
		class is_integral_type<signed char> : public set_is_integral<true, signed char>{};

	template<>
		class is_integral_type<short int> : public set_is_integral<true, short int>{};

	template<>
		class is_integral_type<int> : public set_is_integral<true, int>{};

	template<>
		class is_integral_type<long int> : public set_is_integral<true, long int>{};

	template<>
		class is_integral_type<long long int> : public set_is_integral<true, long long int>{};

	template<>
		class is_integral_type<unsigned char> : public set_is_integral<true, unsigned char>{};

	template<>
		class is_integral_type<unsigned short int> : public set_is_integral<true, unsigned short int>{};

	template<>
		class is_integral_type<unsigned int> : public set_is_integral<true, int>{};

	template<>
		class is_integral_type<unsigned long int> : public set_is_integral<true, long int>{};

	template<>
		class is_integral_type<unsigned long long int> : public set_is_integral<true, long long int>{};


	template<class T>
		class is_integral : public is_integral_type<T> {};

	///////////////////////////////////////////
	//                                       //
	//               Enable_if               //
	//                                       //
	///////////////////////////////////////////


	template<bool Cond, class T>
		class enable_if { };

	template<class T>
		class enable_if<true, T> {
			public:
				typedef T type;
		};
}
