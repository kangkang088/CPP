#include <iostream>
#include <memory>

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

    void Print(){ }
};

int main()
{
    {
        //std::unique_ptr<Entity> entity(new Entity());
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        entity->Print();
    }

    std::shared_ptr<Entity> e0;
    {
        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        std::weak_ptr<Entity> w0 = sharedEntity;
        e0 = sharedEntity;
    }

    std::cin.get();
}


//unique_ptr:不能复制的智能指针，如果复制，那么会有两个指针指向同一块内存，当一个智能指针被释放时，另外一个就会指向无效的内存空间了（回归系统控制）。
//shared_ptr:可以复制的智能指针，采用引用计数，只有当引用计数为0时，指针指向的内存才被释放
//weak_ptr:可以复制shared_ptr，但不会增加shared_ptr的引用计数