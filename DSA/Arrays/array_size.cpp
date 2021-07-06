#include<iostream>
using namespace std;

int main() {
    int *p, *q;
    p = new int[5];
    for(int i = 0; i < 5; i++){
        p[i] = 1 + 2*i;
        // cout << p[i] << endl;
    }
    q = new int[10];
    for(int i = 0; i < 5; i++){
        q[i] = p[i];
    }
    q[5] = 11;
    delete []p;
    p = q;
    q = NULL;
    for(int i = 0; i < 6; i++){
        cout << p[i] << endl;
    }
    return 0;
}