#include <iostream>
#include <string>

// 「友元函数」本质上就是：
// 一个不属于这个类的普通函数，但被这个类授权，可以访问它的私有成员。

class Entity
{
private:
    int x = 10;

    friend void PrintEntity(const Entity& e);
};

void PrintEntity(const Entity& e)
{
    std::cout << e.x << std::endl;
}

int main(){
    Entity e;
    PrintEntity(e);

    std::cin.get();
}


// 常见使用场景是重载 <<：
// class Entity
// {
// private:
//     int x = 10;
// public:
//     friend std::ostream& operator<<(std::ostream& os, const Entity& e);
// };
// std::ostream& operator<<(std::ostream& os, const Entity& e)
// {
//     os << e.x;
//     return os;
// }

// 这样就可以：
// Entity e;
// std::cout << e << std::endl;
// 这里 operator<< 不是 Entity 的成员函数，但它需要访问 Entity 的私有数据，所以常常写成友元函数。