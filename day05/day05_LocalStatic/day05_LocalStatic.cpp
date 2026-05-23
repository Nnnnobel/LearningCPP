//总结：局部静态对象的生命周期贯穿整个程序，但作用域仅限于定义它的函数内部。
#include<iostream>

class Singleton{
public:
    static Singleton& Get(){
        static Singleton instance;
        return instance;

    }

     void Hello()

    {
        std::cout << "Hello" << std::endl;
    }
};

// void Function(){
//     static int i = 0;
//     i++;
//     std::cout << i << std::endl;
// }

int main(){
    // Function();
    // Function();
    // Function();
    // Function();
    Singleton::Get().Hello();

    std::cin.get();
}