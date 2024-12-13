#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name) : m_Name(name), m_Age(-1)
	{
	}

	explicit Entity(int age) :m_Age(age), m_Name("Unknown")
	{
	}
};

int main()
{
	//Entity a = "Cherno"; //不行，因为隐式转换只可以进行一次。
	//Cherno是const char[] ，隐式转换为std::string，而std::string无法再通过Entity的构造函数进行隐式转换了

	Entity a = std::string("Cherno");

	//Entity b = 22;
	Entity b(22);
	Entity b1 = Entity(22);

	std::cin.get();
}