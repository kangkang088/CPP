#include <iostream>

class Entity
{
public:
	virtual void PrintName()
	{
	}
};

class Player :public Entity
{};

class Enemy : public Entity
{};

int main()
{
	Player* player = new Player();
	Entity* actuallyPlayer = player;
	Entity* actuallyEnemy = new Enemy();

	Player* p1 = dynamic_cast<Player*>(actuallyEnemy);//nullptr
	Player* p2 = dynamic_cast<Player*>(actuallyPlayer);//yes

	std::cin.get();
}