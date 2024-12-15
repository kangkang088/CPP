#include <iostream>

//stack:预定义的一个内存区域，通常为2M字节大小,RAM中
//heap:也是一个预定义的内存区域，RAM中

struct Vector3
{
    float x, y, z;
};

int main()
{
    int value = 5;//stack
    int array[5];//stack
    Vector3 vector;//stack

    int* hValue = new int;//heap
    *hValue = 5;
    int* hArray = new int[5];//heap
    Vector3* hVector = new Vector3();//heap

    std::cin.get();
}
//stack的分配与释放，没有任何开销，不需要回退指针并返回指针地址。
//heap分配内存：程序启动时会维护一个叫做空闲列表的东西free list，
//通过free list，可以跟踪哪块内存是空闲的以及位置。
//通过malloc函数请求分配时，会调用底层的特定功能，浏览free list，
//返回一个满足条件的内存空间的指针。
//并记录一些相关信息，比如这块内存被占用，无法再被分配给其他程序等等。

