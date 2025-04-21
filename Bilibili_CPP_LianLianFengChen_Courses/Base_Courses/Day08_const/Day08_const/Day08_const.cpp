#include <iostream>

const int i = 10;

int main()
{
	int const i = 100;

	std::cout << i << std::endl;
	std::cout << ::i << std::endl;
}