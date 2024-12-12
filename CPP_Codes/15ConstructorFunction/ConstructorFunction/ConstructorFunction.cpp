#include <iostream>

class Entity
{
public:
	float x, y;

	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
	Entity()
	{
		x = 1;
		y = 1;
	}
	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

int main()
{
	Entity e;
	e.Print();

	Entity e1 = { 1,2 };
	e1.Print();

	Entity e2 (50,100);
	e2.Print();

	std::cin.get();
}
//this：一个指针，指向它所在的类的一个实例