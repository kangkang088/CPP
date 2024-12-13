#include <iostream>
#include <string>

int main()
{
	//const char* name = "Cherno";//no new,no delete.

	//std::string name = "Cherno" + " hello"; //can't do like this.

	std::string name = "Cherno";
	name += " hello!";

	std::string test = std::string("kk") + " hello";

	std::cout << name << std::endl;

	std::cin.get();
}