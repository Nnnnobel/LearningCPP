//枚举 enum 本质还是 int 一定要是整数
#include<iostream>

enum Example : char {
    A = 0, B = 1, C = 2 //如果不赋值后面默认递增 第一个默认是 0
};


int main(){
    Example value = B;

    if(value == 1){
        //do something
    }
    std::cin.get();
}
