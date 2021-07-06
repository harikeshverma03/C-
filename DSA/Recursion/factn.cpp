
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  fun(int n){
    if (n == 0)
        return 1;
    else 
        return (fun(n-1)*n);
}
int main(){
    int x;
    cout << "Enter a number : ";
    cin >> x;
    fun(x);
    cout << fun(x) << endl;
}