#include <iostream>

int main()
{
	std::cout << "Hello World!\n";

	for (auto i = 0; i < 5; i++)
	{
		std::cout << i + 1 << std::endl;
	}

	while (true)
	{
		std::cout << 1 << std::endl;
		return 0;
	}

	std::cin.get();
}