#include<iostream>
#include <cmath>
using namespace std;
int main(){
    cout << "Enter a Number n" << endl;
    int n;
    cin >> n;
    double i = 0;
    while (i != n-1){
        i = ceil((i+n)/2);
        int j = i;
        cout << j << endl;
    }
}