#include <iostream>
#include <string>

#define String std::string
#define WAIT std::cin.get()
#define OPEN_CURLY {

//可以通过这个实现DEBUG版本输出LOG RELEASE不输出
#define DEBUG 0

#if DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else define(RELEASE)
#define LOG(x)
#endif

#if 0//相当于 false
//中间所有内容失效
#endif

#define MAIN int main \
{\
    std::cin.get();\
}
//反斜杠是Enter的转义




// int main()
// OPEN_CURLY

//     LOG(5);
//     WAIT;
// }