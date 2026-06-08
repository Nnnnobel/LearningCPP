#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
    {

    }

    Vertex(const Vertex& vertex)//构造拷贝函数
        :x(vertex.x), y(vertex.y), z(vertex.z)//shallow copy
    {
        std::cout << "Coppied!" << std::endl;
    }
};

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    vertices.emplace_back(1, 2, 3);//no copy
    vertices.push_back({ 4, 5, 6 });
    vertices.push_back(Vertex(7, 8, 9));

    std::cin.get();
}