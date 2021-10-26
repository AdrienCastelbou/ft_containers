#include <iostream>
#include <vector>

int main()
{
	std::vector<int> iv(3, 100);
	std::vector<int> ivv;

	ivv = iv;
	std::cout << iv[0] << std::endl;
	std::cout << ivv[0] << std::endl;
}
