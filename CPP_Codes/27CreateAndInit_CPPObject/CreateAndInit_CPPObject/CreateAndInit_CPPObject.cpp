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
};

void Function()
{
	Entity entity = Entity("Cherno");
}

int main()
{
	Entity entity;
	std::cout << entity.GetName() << std::endl;

	Entity entity1 = Entity("Cherno");
	std::cout << entity1.GetName() << std::endl;

	Entity* entity2 = new Entity("Cherno");
	std::cout << entity2->GetName() << std::endl;
	delete entity2;

	std::cin.get();
}