#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){
        lchild = rchild = NULL;
    }
    Node(int x){
        data = x;
        lchild = rchild = NULL;
    }
};
void InsertMin(int A[], int n);
void InsertMax(int A[], int n);
void MaxHeap(int A[], int n){
    for(int i = 2; i < n; i++){
        InsertMax(A,i);
    }
}
void InsertMax(int A[], int n){
    int temp, i = n;
    temp = A[n];
    while(i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}
void MinHeap(int A[], int n){
    for(int i = 2; i < n; i++){
        InsertMin(A,i);
    }
}
void InsertMin(int A[], int n){
    int temp, i = n;
    temp = A[n];
    while(i > 1 && temp < A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}
int DeleteMax(int A[], int &n){
    int temp = A[0];
    A[1] = A[n-1];
    n = n-1;
    int i = 1, j = 2*i;
    while(j < n-1){
        if(A[j+1] > A[j])
            j = j+1;
        if(A[i] < A[j]){
            swap(A[i], A[j]);
            i = j;
            j = 2*i;
        }
        else{
            break;
        }
    }
    return temp;
}
int DeleteMin(int A[], int &n){
    int temp = A[0];
    A[1] = A[n-1];
    n = n-1;
    int i = 1, j = 2*i;
    while(j < n-1){
        if(A[j+1] < A[j])
            j = j+1;
        if(A[i] > A[j]){
            swap(A[i], A[j]);
            i = j;
            j = 2*i;
        }
        else{
            break;
        }
    }
    return temp;
}


int main(){
    int A[] = {0, 40,35, 30, 15, 10, 25, 5};
    int n = sizeof(A)/sizeof(A[0]);
    
    MinHeap(A, n);
    for(int i = 1; i< n; i++)
        cout << A[i] << " ";
    cout << endl;
    int x = DeleteMin(A, n);
    for(int i = 1; i< n; i++)
        cout << A[i] << " ";
    cout << endl;

    MaxHeap(A, n);
    for(int i = 1; i< n; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << n << endl;
    x = DeleteMax(A, n);
    for(int i = 1; i< n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << n << endl;

    MaxHeap(A, n);
    for(int i = 1; i< n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}