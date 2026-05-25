//字符串，其实就是字符数组
#include <iostream>
#include <string>

void PrintString(const std::string& string){
    std::cout << string << std::endl;
}

//--------------------------------------------------------------

int main(){
    const char* name = "Nobel";
    char name2[7] = {'N', 'o', 'b', 'e', 'l', '2', 0};
    std::cout << name << std::endl;
    std::cout << name2 << std::endl;

//--------------------------------------------------------------
    std::string name3 = "Nobel3";
    //增：std::string name3 = std::string("Nobel3") + "Hello!";
    bool contains = name3.find("bel") != std::string::npos;
    std::cout << name3 << std::endl;

    std::cin.get();
}