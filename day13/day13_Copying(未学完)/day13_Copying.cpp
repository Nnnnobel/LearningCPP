#include <iostream>
#include <string>
#include <memory>

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
        m_Buffer = new char[m_Size];
        memcpy(m_Buffer, string, m_Size);
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}


int main(){

    std::cin.get();
}