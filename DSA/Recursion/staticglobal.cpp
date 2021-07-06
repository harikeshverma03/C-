#include<iostream>
using namespace std;
int func(int n){
    static int x = 0;
    if (n > 0){
        x++;
        return func(n-1) + x;
    }
    else return 0;
}
int main(){
    int x = 5;
    cout << "Value after recursion of 4 = " ;
    cout << func(x) << endl;
}