#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base Constructed\n";
	}
	virtual ~Base()
	{
		std::cout << "Base Deconstructed\n";
	}
};

class Derived :public Base
{
public:
	Derived()
	{
		std::cout << "Derived Constructed\n";
	}
	~Derived()
	{
		std::cout << "Derived Deconstructed\n";
	}
};

int main()
{
	Base* base = new Base();
	delete base;
	std::cout << "-------------------------\n";
	Derived* derived = new Derived();
	delete derived;
	std::cout << "-------------------------\n";
	Base* poly = new Derived();//Base的析构加上virtual
	delete poly;

	std::cin.get();
}