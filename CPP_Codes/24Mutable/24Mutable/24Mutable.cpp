#include <iostream>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};

int main()
{
	const Entity e;
	e.GetName();

	int x = 8;

	/*auto f = [=]()
		{
			x++;
			std::cout << x << std::endl;
		};*/ //can't do this.

	auto f = [=]() mutable
		{
			x++;
			std::cout << x << std::endl;
		};

	f();//9
	std::cout << x << std::endl;//8 because is == ,not is &

	std::cin.get();
}