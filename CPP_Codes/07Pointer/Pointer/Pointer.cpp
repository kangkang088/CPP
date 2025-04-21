#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
	int var = 8;
	LOG(var);
	int* ptr = &var;
	*ptr = 5;
	LOG(var);
	std::cin.get();

	char* buffer = new char[8];
	memset(buffer, 0, 8);
	delete[] buffer;
}