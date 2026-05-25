#include <iostream>
#include <array>

int main(){
    static const int exampleSize = 5;
    int example[exampleSize];
    int* ptr = example;//这里 ptr 指向数组第一个元素，也就是 example[0]。

    for(int i = 0; i < 5; i++){
        example[i] = 2;
    }

    example[2] = 5;//example实际上也是一个指针
    *(ptr + 2) = 6;//这里 ptr+2 相当于往后移了 2*4 个字节（int = 4 字节）
    //还有一种写法 *(int*)((char*)ptr + 8) = 6;
    std::cout << example[0] << std::endl;
    std::cout << example << std::endl;

    //--------------------------------------------------------------

    // int* another = new int[5];
    // for(int i = 0; i < 5; i++){
    //     another[i] = 2;
    // }

    // delete [] another;

    //--------------------------------------------------------------

    int numbers[5] = {10, 20, 30, 40, 50};//这样也行

    //--------------------------------------------------------------
    //std库里有 std::array
    std::array<int, 5> another;

    for(int i = 0; i < another.size(); i++){
        another[i] = 2;
    }



    std::cin.get();

}
