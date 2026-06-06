#include <iostream>
#include <string>
#include <memory>

//重点：浅拷贝和深拷贝

// struct Vector2
// {
//     float x, y;
// };

// int main(){

//     // Vector2 a = {2, 3};
//     // Vector2 b = a;//拷贝一份 a
//     // b.x = 5;

//     Vector2* a = new Vector2();
//     Vector2* b  = a;//拷贝了a 的地址
//     b -> x = 2;//会影响 a 和 b 因为改变了这个地址里面的东西
//     std::cin.get();
// }

//---------------------------------------------------------------

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    // String(const String& other)
    //     : m_Buffer(other.m_Buffer), m_Size(other.m_Size){} //默认拷贝构造函数 -》 浅拷贝

    String(const String& other)
        : m_Size(other.m_Size)
    {
        std::cout << "Copied String!" << std::endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }


    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string)//always 使用const引用来传递对象
{
    std::cout << string << std::endl;

}


int main()
{
    String string = "Nobel";
    String second = string;

    second[1] = 'a';


    std::cout << string << std::endl;
    std::cout << second << std::endl;

    std::cin.get();
}