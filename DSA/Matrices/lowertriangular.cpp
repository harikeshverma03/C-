#include<iostream>
#include<bits\stdc++.h>
using namespace std;
//This code if for row major formula
//For column major formula replace i*(i-1)/2 + j - 1 with (j-1)*(n-j+2)/2 + (i-j)
class Lowertriangular{
    private:
    int *A;
    int n;
    public:
    Lowertriangular(int sz){
        n = sz;
        A = new int[sz*(sz+1)/2];
        }
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~Lowertriangular(){
        delete []A;
    }
};
void Lowertriangular::set(int i, int j, int x){
    if(i >= j)
        A[i*(i-1)/2 + j - 1] = x;
}
int Lowertriangular::get(int i, int j){
    if(i >= j)
        return A[i*(i-1)/2 + j - 1];
    else 
        return 0;
}
void Lowertriangular::display(){
    cout << "The Lowertriangular is:" << endl;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i >= j)
                cout << A[i*(i-1)/2 + j - 1] << " "; 
            else 
                cout << "0 ";

        }
        cout << endl;
    }
}
int main(){
    Lowertriangular *mat;
    mat = new Lowertriangular(5);
    mat->set(1,1,5);
    mat->set(2,2,6);
    mat->set(3,3,7);
    mat->set(4,4,8);
    mat->set(5,5,9);
    mat->set(2,1,5);
    mat->set(3,1,6);
    mat->set(4,1,7);
    mat->set(5,1,8);
    mat->set(3,2,9);
    mat->set(4,2,5);
    mat->set(5,2,6);
    mat->set(4,3,7);
    mat->set(5,3,8);
    mat->set(5,4,9);
    mat->display();
}