#include <iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int& value)
{
	value++;
}

int main()
{
	int a = 5;
	int& ref = a; //another name of a,no space,no create,pointer can't be changed (ref is always a).
	Increment(ref);
	LOG(a);

	std::cout << "Hello World!\n";
	std::cin.get();
}