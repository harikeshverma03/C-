#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class StackLinked{
    private:
    Node *top;
    public:
    StackLinked(){
        top = NULL;
    }
    void push(int x);
    void pop();
    int Stacktop();
    int size();
    void Display();
    bool empty();
    bool full();
    int peek(int pos);
};
int StackLinked::size(){
    int size = 0;
    Node *p = top;
    while(p != NULL){
        p = p->next;
        size++;
    }
    return size;
}
void StackLinked::Display(){
    Node *p = top;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
bool StackLinked::full(){
    Node *t = new Node();
    if(t == NULL)
        return true;
    else 
        return false;
}
bool StackLinked::empty(){
    if(top == NULL)
        return true;
    return false;
}
void StackLinked::push(int x){
    Node *t = new Node();
    if(t == NULL)
        cout << "Stack Overflow" << endl;
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
void StackLinked::pop(){
    Node *p = top;
    if(p == NULL)
        cout << "Stack Underflow"  << endl;
    else{
        top = p->next;
        delete p;
    }
}
int StackLinked::Stacktop(){
    if(top == NULL)
        return -1;
    return top->data;
}
int StackLinked::peek(int pos){
    if(pos < 1 || pos > size())
        return -1;
    Node *p = top;
    for (int i = 0; i < pos -1; i++)
        p = p->next;
    return p->data;
}
int main(){
    StackLinked *st;
    cout <<"Enter size of stack" << endl;
    int size;
    cin >> size;
    st = new StackLinked();
    int flag = 0;
    cin >> flag;
    do{
        cout << "Enter element to be inserted and -1 to exit" << endl;
        st->push(flag);
        st->Display();
        cin >> flag;
    }while(flag != -1);
    for(int i =0; i < 3; i++, st->pop()) cout << st->Stacktop() << endl;
    st->Display();
    cout << st->size() << endl;
    cout << st->peek(3) << endl;
    cout << st->empty() << endl;
    cout << st->full() << endl;
    st->Display();
    return 0;
    return 0;
}

