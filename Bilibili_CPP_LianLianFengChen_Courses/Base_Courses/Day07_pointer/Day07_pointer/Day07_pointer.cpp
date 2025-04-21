#include <iostream>

int main()
{
	int* p = new int(5);
	std::cout << *p << std::endl;

	int* p1 = nullptr;

	int num = 45;
	int* numPtr = &num;
	int*& numRef = numPtr;
	std::cout << *numRef << std::endl;
	std::cout << *numPtr << std::endl;
}