#include <iostream>

class Entity
{
public:

	float X, Y;

	Entity()
	{
		X = 0; Y = 0;
		std::cout << "Created Entity" << std::endl;
	}

	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	void Print()
	{
		std::cout << X << "," << Y << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity" << std::endl;
	}
};


void Function()
{
	Entity e;
	e.Print();
}

int main()
{
	Function();
	std::cin.get();
}

