#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QueueArray{
    public:
    int size;
    int front;
    int rear;
    int *Q; 
    QueueArray(int siz){
        size = siz;
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void Display();

};
void QueueArray::enqueue(int x){
    if(rear < size - 1){
        Q[++rear] = x;
    }
    else if (rear == size -1)
        cout << "Queue is full" << endl;
}
int QueueArray::dequeue(){
    int x = -1;
    if(front == rear)
        cout << "Queue is empty" << endl;
    else 
        x = Q[++front];
    return x;
}
void QueueArray::Display(){
    for(int i = front + 1; i <= rear; i++)
        cout << Q[i] <<" ";
    cout << endl;
}
int main(){
    QueueArray *Q;
    cout << "Enter size of array" << endl;
    int x;
    cin >> x;
    Q = new QueueArray(x);
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