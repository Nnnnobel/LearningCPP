#include<iostream>

class Entity{
private://只有Entity类和它的友元可以访问这些变量
    int X, Y;

protected://只有Entity类和其所有子类可以访问
    void Print(){};

public://所有人都可以访问
    Entity(){
        X = 0;
    }
};

int main(){


    std::sin.get();
}
//与计算机底层运行和性能无关，完全为了 coder 设计
//private：不应该从其他代码访问这个
//指定可见性可以确保别人不会调用他们不应该接触的代码，造成一些破坏
//提供更好的可读性，以免自己忘记