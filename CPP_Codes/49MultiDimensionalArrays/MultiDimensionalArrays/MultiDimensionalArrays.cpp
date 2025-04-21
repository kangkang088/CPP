#include <iostream>

int main()
{
	int** a2d = new int* [50];

	for (int i = 0; i < 50; i++)
	{
		a2d[i] = new int[50];
	}

	for (int i = 0; i < 50; i++)
	{
		delete[] a2d[i];
	}
	delete[] a2d;

	int*** a2d1 = new int** [50];
	for (int i = 0; i < 50; i++)
	{
		a2d1[i] = new int* [50];
		for (int j = 0; j < 50; j++)
		{
			a2d1[i][j] = new int[50];
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			delete[] a2d1[i][j];
		}
		delete[] a2d1[i];
	}
	delete[] a2d1;

	//多维数组的问题：内存并不连续，可能存在大量内存碎片
	//可以通过一维数组来模拟多维数组解决这个问题

	int* array = new int[5 * 5];
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			array[i + j * 5] = 2;
		}
	}
	delete[] array;

	std::cin.get();
}