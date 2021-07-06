
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void  fun1(int n){
    if (n > 0){
        cout << n << endl;
        fun1(n-1);
    }
}
int main(){
    int x;
    cout << "Enter a number : ";
    x = 4;
    fun1(x);
    cout << "Hello World!" << endl;
}