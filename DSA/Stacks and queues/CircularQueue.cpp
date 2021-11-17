#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*Front and rear starts at 0 and 
Full condition = full = rear + 1
Empty condition = full == rear
maximun number of elements is one less than size of array used*/

class CicularArray{
    public:
    int size;
    int front;
    int rear;
    int *Q; 
    CicularArray(int siz){
        size = siz;
        front = rear = 0;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();

};
void CicularArray::enqueue(int x){
    if((rear+1) % size == front){
        cout << "Queue is full" << endl;
    }
    else{
        rear = (rear + 1) %size;
        Q[rear] = x;
    }
}
int CicularArray::dequeue(){
    int x = -1;
    if(front == rear)
        cout << "Queue is empty" << endl;
    else{
        front = (front + 1)%size;
        x = Q[front];
    }    
    return x;
}
void CicularArray::Display(){
    for(int i = front + 1; i != (rear+1)%size; i= (i+1) %size)
        cout << Q[i] <<" ";
    cout << endl;
}
int main(){
    CicularArray *Q;
    cout << "Enter size of array" << endl;
    int x;
    cin >> x;
    Q = new CicularArray(x);
    int flag;
    cout << "Enter the elements for queue and enter -1 to stop" << endl;
    cin >> flag;
    while(flag != -1){
        Q->enqueue(flag);
        Q->Display();
        cin >> flag;
    }
    Q->Display();
    cout << Q->dequeue() << endl;
    cout << Q->dequeue()  << endl;
    Q->Display();
    return 0;
}