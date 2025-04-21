#include <iostream>
#include "Log.h"

int main()
{
	int a = 5;

	InitLog();
	Log("Hello World!");
	std::cin.get();
}