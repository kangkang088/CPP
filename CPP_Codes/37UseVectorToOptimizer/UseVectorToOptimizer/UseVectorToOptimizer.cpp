#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z) :x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex) :x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex(1, 2, 3)); 
	vertices.push_back(Vertex(4, 5, 6)); 
	vertices.push_back(Vertex(7, 8, 9)); //6次

	std::cout << "-----------------------" << std::endl;

	std::vector<Vertex> vertices1;
	//std::vector<Vertex> vertices1(3); // 这样不行，相当于初始创建了3个Vertex对象放在了vertices1里面

	vertices1.reserve(3);

	vertices1.push_back(Vertex(1, 2, 3));
	vertices1.push_back(Vertex(4, 5, 6));
	vertices1.push_back(Vertex(7, 8, 9)); //3次

	std::cout << "-----------------------" << std::endl;

	std::vector<Vertex> vertices2;

	vertices2.reserve(3);

	vertices2.emplace_back(1, 2, 3);
	vertices2.emplace_back(4, 5, 6);
	vertices2.emplace_back(7, 8, 9); // 0次，通过参数列表，直接让vertices2构建Vertex对象

	std::cin.get();
}