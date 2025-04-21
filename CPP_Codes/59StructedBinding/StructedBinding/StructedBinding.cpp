#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> CreatePerson()// std::pair<parameter1,parameter2>,but std::tuple<parameter1,...,parameterN>
{
	return  { "KangKang",23 };
}

//structed binding：结构化绑定(C++17)
int main()
{
	std::tuple<std::string, int> person = CreatePerson();

	//what is 0 or 1 means? not a good choice
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);

	//better
	std::string name1;
	int age1;
	std::tie(name1, age1) = CreatePerson();

	//better better : structed binding
	auto [name2, age2] = CreatePerson();
	std::cout << name2 << std::endl;
	std::cout << age2 << std::endl;

	std::cin.get();
}