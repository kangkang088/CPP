#include <iostream>
#include <memory>

struct Vector3
{
	float x, y, z;
};
int main()
{
	ScopedPtr entity = new Entity();

	entity->Print();

	std::cin.get();
}