#include <iostream>

class Example
{
public:
	Example()
	{
		std::cout << "Create Example Entity" << std::endl;
	}

	Example(int count)
	{
		std::cout << "Create Example Entity with" << count << std::endl;
	}
};

class Entity
{
private:
	int m_Score;
	std::string m_Name;
	Example example;
public:
	//Entity() : m_Name("Unknown"), m_Score(0)
	//{
	//	example = Example(8);//Create Example Entity
	//                       //Create Example Entity with 8
	//}

	//Entity() : m_Name("Unknown"), m_Score(0), example(Example(8))
	//{
	//	//Create Example Entity with 8
	//}

	Entity() : m_Name("Unknown"), m_Score(0), example(8)
	{
		//Create Example Entity with 8
	}

	Entity(const std::string name, int socre) : m_Name(name), m_Score(socre)
		//无论你写的初始化列表的顺序是啥样的，成员的初始化顺序都按照定义的顺序进行初始化。
	{
	}

	const std::string& GetName() const
	{
		return m_Name;
	}
};

int main()
{
	Entity e;

	std::cin.get();
}