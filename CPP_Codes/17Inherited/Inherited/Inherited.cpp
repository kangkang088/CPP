#include <iostream>

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}

	void PrintPos()
	{ 
		std::cout << X << "," << Y << std::endl;
	}
};

class Player : public Entity
{
public:
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};

int main()
{
	Player player;
	player.X = 1;
	player.Y = 2;
	player.Move(10, 20);
	player.Name = "Jack";
	player.PrintName();
	player.PrintPos();

	std::cout << sizeof(Player) << std::endl;

	std::cin.get();
}

