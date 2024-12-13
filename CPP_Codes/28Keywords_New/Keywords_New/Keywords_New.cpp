#include <iostream>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown")
	{
	}

	Entity(const String& name) : m_Name(name)
	{
	}

	const String& GetName() const
	{
		return m_Name;
	}

	~Entity()
	{
		std::cout << "Deconstructor!" << std::endl;
	}
};

int main()
{
	int a = 2;

	int* b = new int[5];

	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Entity* e1 = new Entity[5];

	delete e;
	delete[] e1;
	delete[] b;

	std::cin.get();
}