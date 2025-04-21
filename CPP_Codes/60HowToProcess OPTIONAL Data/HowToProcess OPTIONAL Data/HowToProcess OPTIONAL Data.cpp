#include <iostream>
#include <fstream>
#include <optional>
//optional data:一些数据可能存在，也可能不存在时，如何处理？

#pragma region Simple
//std::string ReadFileAsString(const std::string& filePath, bool& outSuccess)
//{
//	std::ifstream stream(filePath);
//	if (stream)
//	{
//		std::string result;
//		//read file
//		stream.close();
//		outSuccess = true;
//
//		return result;
//	}
//	outSuccess = false;
//	return std::string();
//}
//
//int main()
//{
//	//这个文件到底有没有被读取成功呢？
//	//这样不是最好的选择，我们想要通过这个方法直接判断出来，而不是通过间接的bool值来判断
//	bool fileOpenSuccessfully;
//	std::string data = ReadFileAsString("data.txt", fileOpenSuccessfully);
//	if (fileOpenSuccessfully)
//	{
//
//	}
//
//
//	std::cin.get();
//}
#pragma endregion

#pragma region Optional
std::optional<std::string> ReadFileAsString(const std::string& filePath)
{
	std::ifstream stream(filePath);
	if (stream)
	{
		std::string result;
		//read file
		stream.close();
		return result;
	}
	return {};
}

int main()
{
	std::optional<std::string> data = ReadFileAsString("data.txt");

	std::string value = data.value_or(std::string("Not present"));
	std::cout << value << std::endl;
	if (data)// or if(data.has_value())
	{
		std::cout << "File read successfully\n";
	}
	else
	{
		std::cout << "File could not be opened\n";
	}
	std::cin.get();
}
#pragma endregion

