#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
};
class Circular{
    public:
    Node* head;
    Circular(){
        Node*t = new Node();
        t->data = 0;
        t->next = t;
        head = t;
    }
    Circular(int A[], int n);
    void Display();
    int Length();
    void DisplayR(Node*p);
    void Insert(int pos, int x);
    int Delete(int pos);
};

Circular::Circular(int A[], int n){
    int i = 0;
    Node *t, *last;
    head = new Node();
    head->data = A[i++];
    head->next = head;
    last = head;
    for(i = 1; i < n; i++){
        t = new Node();
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int Circular::Length(){
    int i = 1;
    Node*p = head->next;
    while(p!=head){
        p = p->next;
        i++;
    }
    return i;
}
void Circular::Display(){
    Node * p = head;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != head);
    cout << endl;
}
void Circular::DisplayR(Node*p){
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " ";
        DisplayR(p->next);
    }else
        cout << endl;
    flag = 0;
}
void Circular::Insert(int pos, int x){
    Node*t, *p;
    if(pos < 0 || pos > Length())
        return;
    t = new Node();
    t->data = x;
    if(pos == 0){
        if(head == NULL){
            head = t;
            t->next = t;
        }
        else{
            p = head;
            while(p->next != head) p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        p = head;
        for(int i = 0; i < pos-1; i++) p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int Circular::Delete(int pos){
    int x;
    if(pos < 0 || pos >Length())
        return -1;
    Node*p = head;
    if(pos == 1){
        while(p->next != head)
            p = p->next;
        x = head->data;
        if(p == head){
            delete head;
            head = NULL;
        }
        else{
            p->next = head->next;
            delete head;
            head = p->next;
        }  
    }
    else{
        for(int i = 0; i < pos -2; i++)
            p =p->next;
        Node*q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}
int main(){
    Circular *cir;
    int A[] = {1, 2, 3, 4, 5};
    cir = new Circular(A, 5);
    cir->DisplayR(cir->head);
    cout << cir->Length() << endl;
    cir->Insert(2,10);
    cir->Delete(1);
    cir->Display();
    return 0;
}