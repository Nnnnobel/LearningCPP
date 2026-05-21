#include<iostream>

int main(){

    //continue 
     for(int i = 0; i < 5; i++ )
     {
        if(i % 2 == 0)
            continue;
        std::cout << "Hello World!" << std::endl;
        std::cout << i << std::endl;
    }


    //break
     for(int i = 0; i < 5; i++ )
     {
        if((i + 1) % 2 == 0)
            break;
        std::cout << "Hello World!" << std::endl;
        std::cout << i << std::endl;
    }

    //return 
    for(int i = 0; i < 5; i++ )
     {
        if((i + 1) % 2 == 0)
            return 0;
        std::cout << "Hello World!" << std::endl;
        std::cout << i << std::endl;
    }


    std::cin.get();
}