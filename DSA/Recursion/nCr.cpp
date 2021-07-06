#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int  fact(int n){
    if (n == 0)
        return 1;
    else 
        return (fact(n-1) *n);
}

int combf(int n, int r){
    int a, b, c;
    a = fact(n);
    b = fact(r);
    c = fact(n-r);
    return (a/(b*c)); 
}
int combp(int n, int r){
    if (r == 0 || n == r)
        return 1;

    else{
        return(combp(n-1,r-1) + combp(n-1, r));
    }
}
    
int main(){
    int x,n;
    cout << "Enter a number : ";
     cin >> x >> n;
    cout << endl;
    cout << combp(x,n) << endl;
}