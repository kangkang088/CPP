#include <iostream>

struct Entity
{
	static int x, y;
	static void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};

int Entity::x;
int Entity::y;

int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;

	e1.x = 5;
	e1.y = 8;

	//Actually
	Entity::x = 8;
	Entity::y = 9;

	e.Print();// 8,9
	e1.Print();// 8,9
	//Actually
	Entity::Print();// 8,9

	std::cin.get();
}
//Static:如果类/结构体中有静态成员，那么对于类的所有实例，共享一份静态成员。静态成员属于类，而非实例对象。
//类/结构体中的静态方法不能访问非静态成员(变量和方法)。因为静态成员属于类，而非实例对象。非静态成员只有在实例对象被创建
//的时候才会有，而静态成员在实例对象没有创建时就已经存在，因为它属于类/结构体。
//注意，如果不是类/结构体中，静态方法是可以调用非静态方法的。

//非静态Print在被调用时，实际的样子
//void Print(Entity e)
//{
//	std::cout << e.x << "," << e.y << std::endl;
//}


//静态Print在被调用时，实际的样子，e不知道是哪个实例，没了
//static void Print()
//{
//	std::cout << e.x << "," << e.y << std::endl;
//}