//day02 Learning Function
#include <iostream>

int Multiply(int a, int b){
    return a * b;
}

int some(){
    return 5 * 8;
}

void other(){
    std::cout << 5 * 8 << std::endl;
}

void MultiplyAndLog(int a, int b){
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main(){
    int result = Multiply(3, 2);
    std::cout << result << std::endl;

    MultiplyAndLog(1,2);
    MultiplyAndLog(112,3232);
    std::cin.get();
}