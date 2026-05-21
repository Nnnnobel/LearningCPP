//Learning Conditional
#include <iostream>
#include "log.h"
using namespace std;

int main(){
    int x = 6;
    bool comparisonResult = x == 5; 
    if(comparisonResult){
        Log("Hello World!");
    }

    if(x == 6)
        Log("Hello World!");

    const char* ptr = nullptr;

    if(ptr){
        Log(ptr);
    }else if(ptr == "Hello"){
        Log("ptr is Hello!");
    }else{
        Log("Fuck u!");
    }

    cout << x << endl;
    cin.get();
}