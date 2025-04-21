#include <iostream>

#pragma region Arrow

//class Entity
//{
//public:
//    void Print() const
//    {
//        std::cout << "Hello!" << std::endl;
//    }
//};
//
//class ScopedPtr
//{
//private:
//    Entity* m_Obj;
//public:
//    ScopedPtr(Entity* entity) : m_Obj(entity)
//    {
//
//    }
//
//    ~ScopedPtr()
//    {
//        delete m_Obj;
//    }
//
//    Entity* operator->()
//    {
//        return m_Obj;
//    }
//};
//
//int main()
//{
//    Entity e;
//    e.Print();
//
//    Entity* ptr = &e;
//    ptr->Print();
//
//    ScopedPtr s = new Entity();
//    s->Print();//对于->，C++底层会进行递归调用
//
//    std::cin.get();
//}

#pragma endregion

#pragma region Arrow Operator Application

struct Vector3
{
	float x, y, z;
};

int main()
{
	int offset = (int)&(((Vector3*)0)->z);

	std::cout << offset << std::endl;

	std::cin.get();
}

#pragma endregion

