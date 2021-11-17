#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class QueueLinked{
    public:
    Node *front;
    Node *rear; 
    QueueLinked(){
        front = rear = NULL;
    }
    void enqueue(int x);
    int dequeue();
    void Display();

};
void QueueLinked::enqueue(int x){
    Node *t = new Node();
    if (t == NULL)
        cout << "Queue is full" << endl;
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}
int QueueLinked::dequeue(){
    int x = -1;
    Node*t = front;
    if(front == NULL)
        cout << "Queue is empty" << endl;
    else{
        x = t->data;
        front = t->next;
        delete t;
    }
    return x;
}
void QueueLinked::Display(){
    Node *p = front;
    while(p!= NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    QueueLinked *Q;
    Q = new QueueLinked();
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