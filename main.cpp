#include <iostream>
#include <vector>

int main()
{
	std::vector<int> iv(3, 100);
	std::vector<int> ivv;
	int f(iv[0]);
	ivv = iv;
	std::cout << iv[0] << std::endl;
	std::cout << ivv[0] << std::endl;
}
