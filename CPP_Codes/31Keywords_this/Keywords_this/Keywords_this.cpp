#include <iostream>

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int GetX() const
    {
        const Entity* e = this;
        return x;
    }
};

int main()
{
    std::cin.get();
}

//this:在类中，表示一个指针，指向所在类的一个实例对象 
