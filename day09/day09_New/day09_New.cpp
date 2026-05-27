#include <iostream>
#include <string>

using String = std::string;

class Entity{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}
    
    const String& GetName() const { return m_Name; }
};

int main(){
    int a = 2;
    int* b = new int[50];

    Entity* e = new Entity();//Entity* e = (Entity*)malloc(sizeof(Entity));
    //唯一的区别是前者调用了Entity Constructor;用 new 更方便


    //用了 new 就必须要用 delete
    delete e;
    delete[] b;
    
    //用 malloc 就要用 free -> free(e);
    std::cin.get();
}