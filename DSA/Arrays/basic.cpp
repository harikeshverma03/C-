#include<iostream>
using namespace std;

int main(){
    int a[5];
    int b[5] = {2, 4, 6, 8, 10};
    int c[5] = {2, 4};
    int d[5] = {0};
    int e[] = {2, 4, 6, 8, 10}; 
    for(int i = 0; i < 5; i++){
        cout << &a[i]<< " " << b[i] << " " << c[i] << " " << d[i] << " " <<  e[i]<< endl;
    }
}
