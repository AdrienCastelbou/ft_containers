#include <iostream>
#include <vector>

int main()
{
	std::vector<int> iv(3);


	iv.push_back(1);
	std::cout << iv.size() << std::endl;
	std::cout << iv.capacity() << std::endl;
}
