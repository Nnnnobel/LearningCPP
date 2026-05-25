#include<iostream>

class Entity{
public:
    float X, Y;

    Entity(){//构造函数 和类同名

        X = 0.0f, Y = 0.0f;
    }

    Entity(float x, float y){//函数重载
        X = x;
        Y = y;
    }
};

//删除构造函数
class Log{
private:
    Log(){}; //or Log() = delete;
public:
    static void Write(){

    }
};

int main(){

    Entity e;
    Entity a(10.0f, 5.0f);
    std::cout << e.X << " , " << e.Y << std::endl;
    std::cout << a.X << " , " << a.Y << std::endl;
    std::cin.get();
}