
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void fun2(int n);
void  fun1(int n){
    if (n > 0){
        cout << n << endl;
        fun2(n-1);
    }
}
void fun2(int n){
    if(n > 0){
        cout << n << endl;
        fun1(n/2);
    } 
}
int main(){
    int x;
    cout << "Enter a number : ";
    x = 20 ;
    fun1(x);
    cout << "Hello World!" << endl;
}