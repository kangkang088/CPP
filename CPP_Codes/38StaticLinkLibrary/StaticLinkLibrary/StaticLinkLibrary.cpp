#include <iostream>
#include <GLFW/glfw3.h>

//“” : 头文件在当前解决方案中的时候使用。如果找不到，它会再去系统标准库路径下寻找
//<> : 头文件在系统标准库路径中的时候使用，找不到就结束了。


int main()
{
    int a = glfwInit();

    std::cout << a << std::endl;

    std::cin.get();
}

