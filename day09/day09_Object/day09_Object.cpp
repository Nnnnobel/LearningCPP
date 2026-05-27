#include <iostream>
#include <string>

using String = std::string;

class Entity{
private:
    String m_Name;
public:
    Entity():m_Name("Unknown"){}
    Entity(const String& name):m_Name(name){}

    const String& GetName() const { return m_Name; }
};

int main(){
    //在栈上分配内存创建
    Entity entity("Nobel");  
    std::cout << entity.GetName() << std::endl;
    //--------------------------
    //在堆上分配内存创建
    Entity* entity1 = new Entity("Nobel");
    std::cout << entity1 -> GetName() << std::endl;
    delete entity1;
    //--------------------------  
    std::cin.get();
}