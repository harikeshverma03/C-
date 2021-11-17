#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
};
class Doubly{
    public:
    Node*first;
    Doubly(){
        first = NULL;
    }
    Doubly(int A[], int n);
    void Display();
    int Length();
    void Insert(int pos, int x);
    int Delete(int pos);
    void Reverse();
};
Doubly::Doubly(int A[], int n){
    Node*t = new Node;
    t->prev = NULL;
    t->next = NULL;
    t->data = A[0];
    first = t;
    Node*p = first;
    for(int i = 1; i < n; i++){
        t = new Node();
        t->data = A[i];
        t->prev = p;
        t->next = p->next;
        p->next = t;
        p = t;
    }
}
void Doubly::Display(){
    Node *p = first;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int Doubly::Length(){
    Node*p = first;
    int i = 0;
    while(p!= NULL){
        p = p->next;
        i++;
    }
    return i;
}
void Doubly::Insert(int pos, int x){
    
    if(pos < 0 || pos > Length())
        return;
    Node*t = new Node();
    t->data = x;
    if(pos == 0){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        Node*p = first;
        for(int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Doubly::Delete(int pos){
    if(pos < 0 || pos > Length())
        return -1;
    int x;
    Node*p = first;
    if(pos == 0){
        first = first->next;
        x = p->data;
        delete p;
        if(first)
            first->prev = NULL;
    }
    else{
        for(int i = 0; i < pos - 1; i++)
            p =  p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}
void Doubly::Reverse(){
    Node*p = first;
    Node*q;
    Node*temp;
    while(p != NULL){
        //cout << p->data << " ";
        temp = p->next;
        p->next =p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next==NULL){
            first = p;
        }
    }
}
int main(){
    Doubly *doub;
    int A[] = {1, 2, 3, 4, 5};
    doub = new Doubly(A, 5);
    doub->Insert(5, 6);
    doub->Display();
    doub->Delete(2);
    doub->Display();
    doub->Reverse();
    doub->Display();
    cout << doub->Length() << endl;
    return 0;
}