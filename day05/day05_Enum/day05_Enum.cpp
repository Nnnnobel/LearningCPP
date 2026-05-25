//枚举 enum 本质还是 int 一定要是整数
//整数在 cpp 里的类型：char 1 字节；short 2 字节；int 4 字节；long 8 字节；long long 8 字节；
#include<iostream>

enum Example : char {//这里的 char 不是「字符内容」，而是在规定这个枚举在底层用什么整数类型存储。 char 是 1 字节，节省空间。
    A = 0, B = 1, C = 2 //如果不赋值后面默认递增 第一个默认是 0
};


int main(){
    Example value = B;//value是example类型 也就是说只能是里面三种数值的其中一种 不然会报错

    if(value == 1){
        //do something
    }
    std::cin.get();
}
