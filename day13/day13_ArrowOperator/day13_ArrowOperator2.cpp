#include <iostream>
#include <string>
#include <cstddef>
//我有一个结构体Vector3，我想得到x，y，z的偏移量
//（x是结构体第一项，偏移量是0；y是第二项，float是4个字节，所以偏移量是4个字节；z的偏移量则是8个字节）
// 可以用箭头运算符来做到，我想访问这些变量，但不是通过有效的内存地址，而是地址从0开始。
struct Vector3 
{
    float x, y ,z;

};

int main()
{
    size_t offset = (std::size_t)&((Vector3*)nullptr) -> y;

    std::cout << offset << std::endl;

    std::cin.get();
}