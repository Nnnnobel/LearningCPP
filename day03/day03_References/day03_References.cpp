#include<iostream>

void Increment1(int value)//复制一份原始变量，不会对原变量造成影响
{
    value++;
}

void Increment2(int* value)//直接引用原始变量，会对原变量造成影响
{
    (*value)++;
}

//一种更简洁的写法 -> 引用
void Increment3(int& value)//直接引用原始变量，会对原变量造成影响
{
    value++;
}


int main(){
    int a = 5;
    //int* b = &a; & -> 取地址
    int& ref = a;//int& -> 是一个整体，表Reference,创造了 a 的一个别名
    std::cout << ref << std::endl;
    Increment1(a);
    std::cout << a << std::endl;
    Increment2(&a);
    std::cout << a << std::endl;
    Increment3(a);
    std::cout << a << std::endl;
    std::cin.get();
}