#include <iostream> // 包含标准输入输出流库

int main()
{
	// 输出字符串
	std::cout << "Hello, World!" << std::endl;

	// 输出数字
	int number = 42;
	std::cout << "The number is: " << number << std::endl;

	// 输出浮点数
	double pi = 3.14159;
	std::cout << "The value of pi is approximately: " << pi << std::endl;

	// 输出字符
	char ch = 'A';
	std::cout << "The character is: " << ch << std::endl;

	// 输出布尔值（C++11及以后）
	bool truth = true;
	std::cout << std::boolalpha; // 启用布尔值的true/false输出
	std::cout << "The truth is: " << truth << std::endl;

	return 0;
}