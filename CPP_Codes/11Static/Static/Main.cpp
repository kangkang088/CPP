#include <iostream>

void Function()
{
}

int main()
{
	std::cout << s_Variable << std::endl;
	std::cin.get();
}

//static:静态。被它修饰的变量或者方法只会在翻译单元内部链接。
//对内开放，对外封闭（两个完全一样的变量，只要是static修饰的，那么链接就不会出错，因为链接的时候，这两个变量只会在自己各自
//所在的翻译单元内部链接）。