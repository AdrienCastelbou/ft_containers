#pragma once
#include <iostream>
#include <vector>

namespace ft {

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

	template<bool Cond, class T>
		class enable_if { };

	template<class T>
		class enable_if<true, T> {
			public:
				typedef T type;
		};
}
