#include <iostream>

struct Entity
{
	int x, y;
};

//type punning:类型双关
int main()
{
	Entity e = { 2,3 };//Entity结构体就两个int数，除此之外啥都没有，我们是不是可以把它看成一个数组

	int* position = (int*)&e;

	std::cout << position[0] << "," << position[1] << std::endl;

	int y = *((int*)((char*)&e + 4));//never
	std::cout << y << std::endl;

	std::cin.get();
}