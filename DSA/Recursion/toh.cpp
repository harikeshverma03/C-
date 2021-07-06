#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void toh(int n, int a, int b, int c){
    
    if (n > 0){
        toh(n-1,a,c,b);
        cout << "Move disk from " << a << " to " << c << endl;
        toh(n-1,b,a,c);
    } 
}
  
int main(){
    int x,n;
    cout << "Enter a number : ";
     cin >> x;
    cout << endl;
    toh(x,1,2,3);
}