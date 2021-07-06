
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double  fun(int x, int n){
    static double p = 1, f = 1;
    if (n == 0)
        return 1;
    else {
        double r = fun(x,n-1);
        p = p*x;
        f = f*n;
        return(r + p/f);
    }     
}
int fun1(int x, int n){
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + x*s/n;
    return fun1(x, n-1); 
}
int fun2(int x, int n){
    static double s = 1;
    for(; n > 0; n--){
        s = 1 + x*s/n; 
    }
    return s;
    }
    
int main(){
    int x,n;
    cout << "Enter a number : ";
     cin >> x >> n;
    cout << endl;
    cout << fun2(x,n) << endl;
}