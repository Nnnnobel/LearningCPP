#include<iostream>

//learning cpp
//Day 1
//c++ variable

int main()
{
    //(unsigned) char,short,int,long,long long,long int
    //float,double
    //bool

    unsigned int variable = 8;
    char a ='A';
    float b = 5.5f;
    double var = 5.2;
    bool boolean = true;

    std::cout << variable << std::endl;
    variable = 20;
    std::cout << variable << std::endl;
    std::cin.get();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << boolean << std::endl;
    std::cout << sizeof(bool) << std::endl;
}


