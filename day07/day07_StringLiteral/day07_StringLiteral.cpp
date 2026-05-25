#include <iostream>
#include <stdlib.h>
// 一个byte等于八个bit

int main(){

//在string后添加内容的新方式:
    using namespace std::string_literals;

    std::string name0 = "Nobel"s + "Hello";


    //--------------------------------------------------------------

    const char* example = R"(Line1
    Line2
    Line3
    Line4)"
    //--------------------------------------------------------------
    const char* Name = u8"Nob\0el";//1byte
    const char Name1[7] = "Nob\0el";
    const wchar_t* Name2 = L"Nobel2";//2byte
    const char16_t* Name3 = u"Nobel3";//2byte
    const char32_t* Name4 = U"Nobel4";//4byte

    // 虽然我们一直说 wchar 每个字符都是 2 字节，
    // 但实际上是由编译器决定的。
    // （Windows：2 bytes，Linux，mac：4 bytes）。 如果你希望它一直是 2 bytes，
    // 你可以用char16_t
    //--------------------------------------------------------------
    std::cout << strlen(Name) << std::endl;
    std::cout << strlen(Name1) << std::endl;
    std::cin.get();
}

//字符数组：char name[] = "Nobel";
//指向字符串字面量：const char* name = "Nobel";