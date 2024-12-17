#include <iostream>
#include <any>

int main()
{
    std::any data;
    data = 2;
    data = "Cherno";
    data = std::string("Hello");

    std::string str = std::any_cast<std::string>(data);

    std::cin.get();
}
//相比于variant，any是类型不安全的
