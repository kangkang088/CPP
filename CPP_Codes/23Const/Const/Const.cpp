#include <iostream>
#include <cstring>

class Entity
{
private:
	int m_X, m_Y;
	mutable int var;
public:
	int GetX() const //only useful in class.常方法，不会修改它所在的类中的任何成员变量
	{
		var = 1;
		//m_X = 2;
		return m_X;
	}

	void SetX(int x)
	{
		m_X = x;
	}
};

void GetValue(Entity& e)
{
	//Entity& ，引用其实是指针常量，所以不可以 e = new Entity()
	e.SetX(5);//指针常量保证的是指针的指向不会改变，至于对象的值，它不管，所以可以调用const和非const方法
	std::cout << e.GetX() << std::endl;
}

void GetValue(const Entity& e)
{
	//Entity& ，引用其实是指针常量，所以不可以 e = new Entity()
	//那么 const Entity& 就是常量指针常量。
	//e.SetX(5);//常量指针常量保证的是指针的指向和指向的值不会改变，所以只能调用const方法。
	std::cout << e.GetX() << std::endl;
}

//const: value never be chaned.
int main()
{
	const int MAX_AGE = 90;
	//a = 10 //not do this.

	int* a = new int;

	a = (int*)&MAX_AGE;//const值可以通过这种方式被改变，但是不建议
	*a = 200;

	std::cin.get();
}

//常量指针：常量的指针，指针指向的值不能变，指向可以变。const int*    int const*
//指针常量：指针的常量，指针指向的值可以改变，指向不能变。int* const
//常量指针常量：啥都不能变 const int* const
//技巧：const先往左看，先碰到谁，谁就是常量