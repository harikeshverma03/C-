#include<iostream>
using namespace std;
int main(){
    cout << "Enter a Number n" << endl;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++ ){
        for(int j = 1;j <=i;j++ ){
            cout << j << " ";
        }
        cout << endl;
    }
}