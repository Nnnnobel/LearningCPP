#include <iostream>
#include <string>

class Entity{
public:
    Entity(){
        std::cout << "Entity Created!" << std::endl;
    }

    ~Entity(){
        std::cout << "Entity Destroyed!" << std::endl;
    }
};

// int* CreateArray(){
//     int array[50];//在 stack 上声明 正确方式 1：int* array = new int[50];
//     return array;//指向栈内存的指针
// }//离开这个作用域就会被清除

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr)
    :m_Ptr(ptr) {}

    ~ScopedPtr(){
        delete m_Ptr;
    }
};

int main(){

    // int* a = CreateArray();//这是成立不了的
    {
        Entity e;//在 stack 上创建，出作用域就被销毁

        Entity* e1 = new Entity();//在 heap 上创建，不会被自动销毁

        ScopedPtr e2 = new Entity();//超出作用域会被销毁 用 new 会智能转换

        delete e1;

    }

    std::cin.get();
}