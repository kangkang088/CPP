#include <iostream>
#include <cstring>

//string literal
//string literal is always in the const areas.
int main()
{
	"Cherno";//const char* C h e r n o \0

	const char name[8] = u8"Che\0rno"; // char = 1个字节
	std::cout << strlen(name) << std::endl;//3  strlen will not caculate the \0,and end when it meets \0

	const wchar_t* name2 = L"Cherno"; //char = 2个字节 maybe

	const char16_t* name3 = u"Cherno"; //char = 2个字节 must be
	const char32_t* name4 = U"Cherno"; //char = 4个字节

	//wchar_t 和 char16_t的区别：wchar_t的单个char的字节是不确定的，可能是1个，也可能是2个（Windows），也可能是4个（Linux），大多数情况是2个16位
	//char16_t的单个char的字节是确定的，一定是2个16位

	using namespace std::string_literals;

	std::string name_0 = u8"Cherno"s + " hello";
	std::string name_0_0 = "Cherno"s + " hello";
	std::wstring name_1 = L"Cherno"s + L" hello";
	std::u16string name_2 = u"Cherno"s + u" hello";
	std::u32string name_3 = U"Cherno"s + U" hello";

	const char* example = R"(Line1
Line2
Line3
Line4)";
	// Line1
	// Line2
	// Line3
	// Line4

	const char* exp = "Line1\n"
		"Line2\n"
		"Line3\n";

	std::cout << example << std::endl;
	// Line1
	// Line2
	// Line3

	std::cin.get();
}

//char* name = "Cherno";
//name[2] = 'a';
//不能这样写，因为字符串实际是存在于内存中的常量区，不可以修改，虽然编辑器不会报错，但是在release模式下，最后的结果依然是Cherno，在Debug下，会抛异常。
//通过汇编代码会发现，"Cherno"其实是被定义为const

//想要修改，则要Char name[] = "Cherno";
//name[2] = 'a';
//string literal is always in the const areas.但是上面的语句其实会对常量区的Cherno进行拷贝。
//创建一个新的临时的Cherno，在栈上，并把指针name的值重新赋值，指向新的Cherno。