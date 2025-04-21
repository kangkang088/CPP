#include <iostream>

class Base
{
public:
	Base()
	{
	}
	virtual ~Base()
	{
	}
};

class Derived : public Base
{
public:
	Derived()
	{
	}
	~Derived()
	{
	}
};

class AnotherClass : public Base
{
public:
	AnotherClass()
	{
	}
	~AnotherClass()
	{
	}
};

int main()
{
	double value = 5.25;
	double a = (int)value + 5.3;
	std::cout << a << std::endl;//10.3

	double s = static_cast<int>(value) + 5.3;
	std::cout << s << std::endl;//10.3

	Derived* derived = new Derived();

	Base* base = derived;

	Derived* ac = dynamic_cast<Derived*>(base);

	if (ac)
	{
		std::cout << "Succeed" << std::endl;
	}

	std::cin.get();
}