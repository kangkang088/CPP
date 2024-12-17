#include <iostream>

namespace Apple
{
	void Print(const char* text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange
{
	void Print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

int main()
{
	Apple::Print("Hello");

	std::cin.get();
}