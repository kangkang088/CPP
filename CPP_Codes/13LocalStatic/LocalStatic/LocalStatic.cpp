#include <iostream>

void Function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Function();// 1
    Function();// 2
    Function();// 3
    std::cin.get();

    Player::Get().Print();
}

//Local Static：局部静态
//生命周期等于整个程序的生命周期，但是作用域仅限于声明它的某个作用域（比如某个函数中，if中...）,所以当这个作用域多次
//执行时，每次执行，它的初始值，都是上次作用域执行完后结束的值

//int i = 0;
//把它声明到这里，作为全局变量，其实效果也一样，但是这样的话，任意地方都可以访问到i。
//如果想做到让某个区域访问，而值又只被初始化一次，那么就可以局部静态。

class Player
{
public:
    static Player& Get()//创建一个静态实例，也就是一直会存在的一个实例对象（单例）
    {
        static Player instance;//只会初始化一次的对象，之后每一次改变都是继承上次的
        return instance;
    }

    void Print()
    {
        std::cout << "Instance" << std::endl;
    }
};
  