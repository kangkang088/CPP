#include <iostream>

//void Print(int* p)
//{
//}

int main()
{
	int example[5];

	//Print(example);//证明example是一个指针

	int* ptr = example;

	example[0] = 1;// *(example + 0)
	example[1] = 1;// *(example + 1)
	example[2] = 1;
	example[3] = 1;
	example[4] = 1;

	*(ptr + 4) = 2;

	for (int i = 0; i < sizeof(example) / sizeof(int); i++)
		std::cout << example[i] << std::endl;

	std::cin.get();
}

