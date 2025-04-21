#include <iostream>

int main()
{
	std::cout << "Hello World!\n";

	int x = 5;
	if (x > 5)
		std::cout << "x Greater Five" << std::endl;
	else if (x < 5)
		std::cout << "x Lower Five" << std::endl;
	else
		std::cout << "x equals to Five" << std::endl;
}