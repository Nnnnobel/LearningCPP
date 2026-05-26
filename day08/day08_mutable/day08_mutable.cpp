#include <iostream>
#include <string>

//mutable主要在 class 中使用
class Entity{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;//mutable

public:
    const std::string& GetName() const{//1. 前面的 const：不能通过返回结果修改 m_Name 2. 后面的 const：这个函数不允许修改当前对象
        m_DebugCount ++;
        return m_Name;
    }
};

int main(){
    const Entity e;
    e.GetName();

    // int x = 8;
    // auto f = [=]() mutable{  //auto -> 自动决定变量类型
    //     x++;
    //     std::cout << x << std::endl;
    // };

    std::cin.get();
}

//-------------------------------------------------------------------

