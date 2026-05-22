#include<iostream>

int main(){

    // int var = 8;
    // int* ptr = &var;//这里的&是取地址符
    
    // //指针只是一个指向内存地址的 int；
    // // 与前面写的 type 无关；
    // //void* ptr = nullptr;
    // //void* ptr = NULL;
    // //void* ptr = 0;
    // *ptr = 10;  
    // std::cout << *ptr << std::endl;


    char* buffer = new char[8];
    memset(buffer, 0, 8);
    delete[] buffer;


    //double pointer
    char** ptr = &buffer;


    //换指向
    int a = 5;
    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;

    std::cin.get();
}