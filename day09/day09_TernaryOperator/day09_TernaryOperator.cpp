#include <iostream>
#include <string>
//只是 if 语句的语法糖

static int s_Level = 1;
static int s_Speed = 2;

int main(){
    // if(s_Level > 5){
    //     s_Speed = 10;
    // }else{
    //     s_Speed = 5;
    // }

    s_Speed = (s_Level > 5) ? (s_Level > 10) ? 15 : 10 : 5;//技术上可行但不建议这样写；

    std::string rank = s_Level > 10 ? "Master" : "Beginner";

    std::cin.get();
}