
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  fun(int n){
    if (n == 0)
        return 0;
    else if (n==1)
        return 1;
    else 
        return(fun(n-1) + fun(n-2));
    
}
int fibfor(int n){
    int a = 0, b = 1,s=0;
    if (n <=1) return n;
    for (int i = 2; i <= n; i++){
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}
int f[100];
int fibmem(int n){
    if (n <= 1){
        f[n] = n;
        return n;
    }
    else {
        if (f[n-1] == -1){
            f[n-1] = fibmem(n-1);
        }
        if (f[n-2] == -1){
            f[n-2] = fibmem(n-2);
        }
        return(f[n-1] + f[n-2]);
    }
        
}
int main(){
    int x;
    cout << "Enter a number : ";
    cin >> x;
    cout << endl;
    for(int i = 0; i < x; i++){
        f[i] = -1;
    }
    cout << fibmem(x) << endl;
}