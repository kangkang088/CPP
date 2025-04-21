#include <iostream>

void Log(const char* message); //declaration

int main()
{
	Log("Hello World!");
	std::cin.get();
}

//compile：->.obj file
//1.预处理
//2.符号化和解析

//link: combine .obj files