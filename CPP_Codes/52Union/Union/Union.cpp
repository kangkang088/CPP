#include <iostream>

struct Vector2
{
	float x, y;
};
struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << "," << vector.y << std::endl;
}

//union:通常来说，union是匿名使用的，但是匿名union不能有成员函数
int main()
{
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << "," << u.b << std::endl;//2,10xxxxx  后面的u.b的值其实是 在浮点数形式的2 的 字节表示里面，取int大小的字节，解释为int 的值。
	//这就好像我们取了组成浮点数的内存，并解释为一个整形。所以union常被用来类型双关。

	Vector4 vecotr = { 1.0f,2.0f,3.0f,4.0f };
	PrintVector2(vecotr.a);
	PrintVector2(vecotr.b);
	vecotr.z = 500.f;
	PrintVector2(vecotr.a);
	PrintVector2(vecotr.b);

	std::cin.get();
}