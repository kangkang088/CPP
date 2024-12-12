#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
	int x, y;
	int speed;
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};

int main()
{
	Player player;
	player.x = 5;
	player.y = 6;
	player.speed = 60;
	player.Move(1, -1);

	std::cout << "Hello World!\n";
	std::cin.get();
}

//compare with struct:
//1.default : struct is public.class is private.
//2.struct is to fix with C language
//3.class can be inherited