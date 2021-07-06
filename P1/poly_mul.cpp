#include<iostream>
#include<vector>
using namespace std;
vector<int> Multpoly_n(vector<int> A, vector<int> B, int n){
    vector<int> arr(2*n-1);
    for(int i = 0; i < 2*n-1; i++){
        arr.push_back(0);
        
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i+j] = arr[i+j] + A[i] * B[j];
        }
    }
    return arr;
}
int main(){
    vector<int> A;
    vector<int> B;
    int n,temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        B.push_back(temp);
    }
    vector<int> a = Multpoly_n(A, B, n);
    for(int i = 0; i < 2*n-1; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}