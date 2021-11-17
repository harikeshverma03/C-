#include<iostream>
#include<bits\stdc++.h>
using namespace std;
//This code if for row major formula
//For column major formula replace i*(i-1)/2 + j - 1 with (j-1)*(n-j+2)/2 + (i-j)
class Tridiagonal{
    private:
    int *A;
    int n;
    public:
    Tridiagonal(int sz){
        n = sz;
        A = new int[3*n-2];
        }
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~Tridiagonal(){
        delete []A;
    }
};
void Tridiagonal::set(int i, int j, int x){
    if(i - j == 1)
        A[i-2] = x;
    else if (i - j == 0)
        A[n + i - 2] = x;
    else if (i - j == -1)
        A[2*n-1 + i - 1] = x;
}
int Tridiagonal::get(int i, int j){
    if(i - j == 1)
        return A[i-2];
    else if (i - j == 0)
        return A[n + i - 2];
    else if (i - j == -1)
        return A[2*n-1 + i - 1];
    else 
        return 0;
}
void Tridiagonal::display(){
    cout << "The Tridiagonal Matrix is:" << endl;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i - j == 1)
                cout << A[i-2] << " ";
            else if (i - j == 0)
                cout << A[n + i - 2] << " ";
            else if (i - j == -1)
                cout << A[2*n-1 + i - 1] << " ";
            else 
                cout << "0 ";

        }
        cout << endl;
    }
}
int main(){
    Tridiagonal *mat;
    int n;
    cout <<"Enter the dimensions of the matrix :" << endl;
    cin >> n;
    mat = new Tridiagonal(n);
    int x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            mat->set(i,j,x);
        }
    }
    mat->display();
}