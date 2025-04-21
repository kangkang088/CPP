#include <iostream>

//void Print(int* p)
//{
//}

int main()
{
	int example[5];//in stack,until }

	//Print(example);//证明example是一个指针
	//std::cout << sizeof(example) << std::endl; // 20-数组的大小
	//通过sizeof获取数组的大小，数组必须是在栈上分配的。堆上分配的数组不行。
	//但是就是是栈上的数组，也建议不要通过这种方式计算，而是自己显示定义一个数组的大小，自己维护。

	int* another = new int[5];//in heap,until program end.
	//std::cout << sizeof(another) << std::endl; // 8(x64)-指针的大小

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