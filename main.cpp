#include <iostream>
#include <vector>
#include "vector.hpp"
#include <list>

#include "vector.hpp"
#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# define GOOD "✓"
# define FAIL "❌"

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

void	test_vector(void);
void	test_list(void);
void	test_map(void);
void	test_stack(void);
void	test_queue(void);

inline void print_header(std::string str)
{
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << BLUE << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << RESET;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(38 - name.length(), ' ');
	if (a == b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(38 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

#endif

int		main(void)
{
	print_header("Insert");
	int test[] = {1, 2, 3};
	(void) test;
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 42);
	v1.insert(v1.end(), 21);
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin() + 1, 11);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v1.insert(v1.begin() + 1, test, test + 3);
	v2.insert(v2.begin(), 42);
	v2.insert(v2.end(), 21);
	v2.insert(v2.begin(), 10);
	v2.insert(v2.begin() + 1, 11);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 1, test, test + 3);
	check("v1 == v2", v1 == v2);
}
