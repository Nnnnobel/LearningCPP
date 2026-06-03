#include <iostream>
#include <string>
#include <memory>

class Entity{
public:
    Entity(){
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity(){
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print(){}
};

int main(){
    {
         std::unique_ptr<Entity> entity = std::make_unique<Entity>();    //(new Entity());

        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();    
        //(new Entity());不要使用这个 因为这个得做两次初始化 前面的语句一次性把初始化和分配控制内存块都做完了
        std::shared_ptr<Entity> e0 = sharedEntity;

        std::weak_ptr<Entity> WeakEntity = sharedEntity;//和shared_ptr复制的区别是 weak 不会增加计数 但其他都一样

        entity -> Print();

    }
    std::cin.get();
}

