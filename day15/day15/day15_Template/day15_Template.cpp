#include <iostream>
#include <string>

// void Print(int value)
// {
//     std::cout << value << std::endl;
// }

// void Print(std::string value)
// {
//     std::cout << value << std::endl;
// }

// void Print(float value)
// {
//     std::cout << value << std::endl;
// }

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    Print<int>(5);
    Print<std::string>("Hello");
    Print(5.5f);

    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;
    std::cin.get();
}
