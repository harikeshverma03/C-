
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int  fun(int m,int n){
    if (n == 0)
        return 1;
    else 
        return (fun(m,n-1)*m);
}
int powop(int m, int n){
    if (n == 0)
        return 1;
    if(n%2 ==0)
        return powop(m*m,n/2);
    else 
        return (m*powop(m*m, (n-1)/2));
}
int main(){
    int m,x;
    cout << "Enter a number : ";
    cin >> m >> x;
    cout << powop(m,x) << endl;
}