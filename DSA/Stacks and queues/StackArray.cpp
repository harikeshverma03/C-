#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int *s;
    Stack(int siz){
        size = siz;
        s = new int[size];
        top = -1;
    }
    void push(int x);
    int pop();
    int Stacktop();
    int peek(int pos);
    bool empty();
    bool full();
    void Display();

};
void Stack::push(int x){
    if(top == size -1)
        cout << "Stack Overflow" << endl;
    else{
        s[++top] = x;
    }
}
void Stack::Display(){
    for(int i = top; i >= 0; i--)
        cout << s[i] << " ";
    cout << endl;
}
int Stack::pop(){
    int x = -INT_MAX;
    if(top == -1)
        cout << "Stack Underflow" << endl;
    else{
        x = s[top];
        s[top--] = 0;
    }
    return x;
}
bool Stack::full(){
    if(top ==size -1)
        return true;
    return false;
}
bool Stack::empty(){
    if(top == -1)
        return true;
    return false;
}
int Stack::Stacktop(){
    if(top == -1)
        return -1;
    return s[top];
}
int Stack::peek(int pos){
    if(top - pos + 1 < 0 || pos < 1){
        cout << "Invalid pos" << endl;
        return -1;
    }
    return s[top - pos + 1];
}
int main(){
    Stack *st;
    cout <<"Enter size of stack" << endl;
    int size;
    cin >> size;
    st = new Stack(size);
    int flag = 0;
    while(flag != -1){
        cout << "Enter element to be inserted and -1 to exit" << endl;
        cin >> flag;
        st->push(flag);
        st->Display();
    }
    for(int i =0; i < 3; i++) cout << st->pop() << endl;
    st->Display();
    cout << st->peek(3) << endl;
    cout << st->empty() << endl;
    cout << st->full() << endl;
    st->Display();
    return 0;
}