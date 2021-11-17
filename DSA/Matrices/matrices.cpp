#include<iostream>
#include<bits\stdc++.h>
using namespace std;
class Diagonal{
    private:
    int *A;
    int n;
    public:
    Diagonal(int sz){
        n = sz;
        A = new int[sz];
        }
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    ~Diagonal(){
        delete []A;
    }
};
void Diagonal::set(int i, int j, int x){
    if(i == j)
        A[i-1] = x;
}
int Diagonal::get(int i, int j){
    if(i == j)
        return A[i-1];
    else 
        return 0;
}
void Diagonal::display(){
    cout << "The Diagonal is:" << endl;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < i; j++)
            cout << "0 ";
        cout << A[i] << " ";
        for(int k = i+1; k < n; k++)
            cout << "0 ";
        cout << endl;
    }
}
int main(){
    Diagonal *mat;
    mat = new Diagonal(5);
    mat->set(1,1,5);
    mat->set(2,2,6);
    mat->set(3,3,7);
    mat->set(4,4,8);
    mat->set(5,5,9);
    mat->display();

}