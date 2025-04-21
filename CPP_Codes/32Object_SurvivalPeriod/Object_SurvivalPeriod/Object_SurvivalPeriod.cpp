#include <iostream>

//class Entity
//{
//public:
//    Entity()
//    {
//        std::cout << "Created Entity!" << std::endl;
//    }
//    ~Entity()
//    {
//        std::cout << "Destroyed Entity!" << std::endl;
//    }
//};
//
////survival period
//int main()
//{
//    {
//        Entity e; //in stack
//    }
//    //Created Entity!
//    //Destroyed Entity!
//
//    {
//        Entity* e = new Entity(); //in heap
//    }
//    //Created Entity!
//
//    std::cin.get();
//}


class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr) : m_Ptr(ptr)
	{
	}
	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

//survival period
int main()
{
	{
		ScopedPtr e = new Entity();//implicit,因为e是在栈上分配的，所以它会自动销毁，那么析构函数就会调用，那么指针Entity就自动被释放了
	}
	//Created Entity!
	//Destroyed Entity!

	std::cin.get();
}

