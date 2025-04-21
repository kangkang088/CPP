#include <iostream>

#pragma region wide copy
//class String
//{
//private:
//    char* m_Buffer;
//    unsigned int m_Size;
//public:
//    String(const char* string)
//    {
//        m_Size = strlen(string);
//        m_Buffer = new char[m_Size + 1];
//
//        /*for (int i = 0; i < m_Size; i++)
//            m_Buffer[i] = string[i];*/
//        memcpy(m_Buffer, string, m_Size);
//        m_Buffer[m_Size] = 0;
//    }
//
//    ~String()
//    {
//        delete[] m_Buffer;
//    }
//
//    char& operator[](unsigned int index)
//    {
//        return m_Buffer[index];
//    }
//
//    friend std::ostream& operator<<(std::ostream& stream, const String& string);
//};
//
//std::ostream& operator<<(std::ostream& stream, const String& string)
//{
//    stream << string.m_Buffer;
//    return stream;
//}
//
//int main()
//{
//    String string = "Cherno";
//    std::cout << string << std::endl;
//
//    String second = string;
//    std::cout << second << std::endl;
//
//    string[2] = 'a';
//
//    std::cout << string << std::endl;
//    std::cout << second << std::endl;
//
//    std::cin.get();
//}
//程序异常终止
//上面的是浅拷贝，只会单纯的拷贝值，那么就会有两个指针的值是一样的，指向同一块内存空间。
//当对象生命周期结束，析构函数被调用，第一个释放的时候不会有问题，但是第二个指向的内存空间和第一个是一样的。
//第二个释放的时候就会出现异常，因为程序在释放一块已经释放了的内存空间。

#pragma endregion

#pragma region deep copy
class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];

        /*for (int i = 0; i < m_Size; i++)
            m_Buffer[i] = string[i];*/
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    //String(const String& other) : m_Buffer(other.m_Buffer),m_Size(other.m_Size){ } //C++默认提供的拷贝构造函数 
    String(const String& other) :m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);//other已经是一个字符串看，必须要终止字符，所以我们拷贝size+1的大小。
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    String string = "Cherno";
    std::cout << string << std::endl;

    String second = string;
    std::cout << second << std::endl;

    string[2] = 'a';

    std::cout << string << std::endl;//Charno
    std::cout << second << std::endl;//Cherno

    std::cin.get();
}
//深拷贝，程序不会出异常

#pragma endregion




