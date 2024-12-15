#include <iostream>

//template:在编译时就会被处理 

#pragma region Method
//template<typename T>
//void Print(T value)//不是一个真正的函数，在被调用时，根据类型，生成具体的函数。
////如果从未调用过，即使里面有语法错误，也不会报错，因为它从来没有实际存在过(编译时删除)
//{
//    std::cout << value << std::endl;
//}
//
//int main()
//{
//    //Print(5);
//    Print<int>(5);//生成函数：void Print(int value)
//
//    //Print("Hello");
//    Print<std::string>("Hello");//生成函数：void Print(std::string value)
//
//    //Print(5.5f);
//    Print<float>(5.5f);//生成函数：void Print(float value)
//
//
//    std::cin.get();
//}
#pragma endregion

#pragma region Class
template<typename T,int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const
    {
        return N;
    }
};

int main()
{
    Array<int,5> _array;
    std::cout << _array.GetSize() << std::endl;

    std::cin.get();
}
#pragma endregion




