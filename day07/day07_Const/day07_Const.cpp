#include<iostream>

class Entity{
private:
    int m_X, m_Y;
    mutable int var;//mutable允许函数是const方法 但是可以修改变量

    //int* m_X, m_Y; -> m_X是指针 m_Y还是 int //int* m_X, *m_Y;

public:
    int GetX() const{//getter函数，const 放在方法名右侧（只在类中有效），表示只读不写
        var = 2;
        return m_X;
    }

    void SetX(int x){//setter函数
        m_X = x;
    }
};

void PrintEntity(const Entity& e){
    std::cout << e.GetX() << std::endl;
}

int main(){

    Entity e;

    const int Max_Age = 90;

    // //1.不能改变该地址存储的内容，但是可以改变指针指向的地址
    // const int* a = new int;
    // a = (int*)&Max_Age;

    // //2.不能改变指针指向的地址 但是可以改变该地址存储的内容 
    // int* const a = new int;
    // *a = 2;


    // const 在 * 前面：指针指向的内容不能通过该指针修改，
    // 例：const （int* a）; 这个是一个整体 表示指针指向的内容被 const 了

    // const 在 * 后面：指针自己不能改为指向别处，
    // 例：int* const （a）; 后面是一个单独指针 表示指向的地址被 const了
    

    // std::cout << *a << std::endl;
    std::cin.get();
}