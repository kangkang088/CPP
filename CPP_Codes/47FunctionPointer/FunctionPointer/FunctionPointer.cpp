#include <iostream>
#include <vector>

void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void HelloWorld(int a)
{
	std::cout << "Hello World! Value:" << a << std::endl;
}

void ForEach(const std::vector<int>& values,void(*func)(int))
{
	for (int value : values)
		func(value);
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

int main()
{
	void(*function)() = HelloWorld;
	function();

	typedef void(*HelloWorldFunction)(int);
	HelloWorldFunction func = HelloWorld;
	func(2);

	std::vector<int> values = { 1,5,4,2,3 }; 
	ForEach(values,PrintValue);//函数名就是一个指针（地址），指向函数的起始位置。

	std::cin.get();
}

