#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
};

//记得引用传参

void Function(const std::vector<Vertex>& vertices){

}

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << " , " << vertex.y << " , " << vertex.z;
    return stream;
}

int main(){
    // Vertex* vertices = new Vertex[5];
    std::vector<Vertex> vertices;
    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 4, 5, 6 });

    Function(vertices);

    for(int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;

    // vertices.clear();
    vertices.erase(vertices.begin() + 1);

    for(const Vertex& v : vertices)
        std::cout << v << std::endl;




    std::cin.get();
}