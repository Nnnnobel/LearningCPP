//explicit禁用implicit 关键字放在构造函数前面 意味着你必须显式调用构造函数
//implicit cpp 隐式转换，编译器自动把一种类型转换为另一种类型
#include <iostream>
#include <string>
using String = std::string;

class Entity{
private:
    String m_Name;
    int m_Age;
public:
    Entity(const String& name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int Age) : m_Name("Unknown"), m_Age(Age) {}

};

void PrintEntity(const Entity& entity){
    //Printing
 }


int main(){
    PrintEntity(Entity(22));
//Implicit
    Entity a = String("Nobel");
    Entity b = Entity(22);//Entity b(22)  -> Explicit


    std::cin.get();
}