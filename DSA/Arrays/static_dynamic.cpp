#include<iostream>
using namespace std;

int main(){
    
    int arr[5] = {2, 4, 6, 8, 10};
    int *p;
    p = new int[5];
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
    for (int i =0; i < 5; i++){
        cout << arr[i] << " " << p[i] << endl;
    }
        
    
}