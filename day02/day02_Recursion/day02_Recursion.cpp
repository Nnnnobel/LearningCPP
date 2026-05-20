//Learning Recursion 学习递归

#include<iostream>
using namespace std;

//example 01 ->

// int factorial(int n){
//     if(n == 1){
//         return 1;
//     }else{
//         return n * factorial(n - 1);
//     }
// }

// int printNum(int n){
//     if(n == 0){
//         return;
//     }
//     printNum(n - 1);
//     cout << n << endl;
    
// }

void Hanoi(int n, char A, char B, char C){
    if(n == 1){
        cout << " Move disk 1 from " << A << " to " << C << endl;
        return;
    } 

    Hanoi(n - 1, A, C, B);

    cout << " Move disk " << n << " from " << A << " to " << C << endl;

    Hanoi(n - 1, B, A, C);


}

int main(){
    int n = 5;
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}