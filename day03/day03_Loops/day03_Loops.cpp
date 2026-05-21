#include<iostream>

int main(){


    //01.for Loops

    for(int i = 0; i < 5; i++ ){//先执行 i++，再检查 i 与 5 的关系（重点）
        std::cout << "Hello World!" << std::endl;
    }


    // int i = 0;

    // for( ; i < 5;   ){
    //     std::cout << "Hello World!" << std::endl;
    //     i++;
    // }
    
    std::cout << "------------------------" << std::endl;

    //02.while Loops

    int i = 0;
    while(i < 5){
        std::cout << "Hello World!" << std::endl;
        i++;
    }

    std::cout << "------------------------" << std::endl;

    //03.do while Loop

    bool condition = false;
    do{
        std::cout << "Fuck U!" << std::endl;
        i++;
    }while(condition);

    std::cin.get();
}