#include <iostream>
#include <variant>
//std::variant ： 不确定一个变量的类型，可以先列出它可能的所有类型

int main()
{
    std::variant<std::string, int> data;
    data = "Cherno";
    std::cout <<  data.index() << std::endl;
    std::cout << std::get<std::string>(data) << "\n";//Cherno
    data = 2;
    std::cout << data.index() << std::endl;
    std::cout << std::get<int>(data) << "\n";//2

    std::cout << "--------------------------------\n";

    if (auto value = std::get_if<std::string>(&data))
    {
        std::string& v = *value;
    }
    else if(auto value = std::get_if<int>(&data))
    {
        int& a = *value;
    }

    std::cin.get();
}

//data.index():data数据当前类型在所有可能类型中的索引
//不同于union，variant的大小是总和，而不是最大的