#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3() :x(10), y(11), z(12)
	{
	}
};

int main()
{
	int value = 4;
	int array[5]{ 1,2,3,4,5 };
	Vector3 vector;

	int* hvalue = new int;
	*hvalue = 4;
	int* harray = new int[5];
	Vector3* hvector = new Vector3();

	std::cin.get();
	delete hvalue;
	delete[] harray;
	delete hvector;

	return 0;
}