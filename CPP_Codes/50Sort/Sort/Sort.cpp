#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 1,5,4,3,2 };
	//std::sort(values.begin(), values.end(), std::greater<int>());
	std::sort(values.begin(), values.end(), [](int a, int b)//true：a在b的前面，false，a在b的后面
		{
			if (a == 1)
				return false;
			if (b == 1)
				return true;
			return a < b;
		});

	for (int value : values)
	{
		std::cout << value << std::endl;
	}

	std::cin.get();
}