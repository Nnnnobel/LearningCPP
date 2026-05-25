#include<iostream>

class Entity{
public:
    float X, Y;

    Entity(){
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity! " << std::endl;
    }

    void Print(){
        std::cout << X << " , " << Y << std::endl;
    }

    ~Entity(){
        std::cout << "Destroyed Entity! " << std::endl;
    }

};

void Function(){
    Entity e;
    e.Print();
    e.~Entity();//可以像正常函数一样被调用 但基本不会有人这样写
}

int main(){

    Function();
    std::cin.get();
}