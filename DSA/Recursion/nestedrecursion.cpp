
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  fun(int n){
    if (n > 100)
        return (n-10);
    else 
        return fun(fun(n+11));
}
int main(){
    int x;
    cout << "Enter a number : ";
    x = 99 ;
    fun(x);
    cout << fun(x) << endl;
}