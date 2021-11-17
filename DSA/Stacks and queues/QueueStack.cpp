#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QueuStack{
    public:
    stack<int>s1;
    stack<int>s2;
    QueuStack(){
    }
    void enqueue(int x);
    int dequeue();
    void Display();

};
void QueuStack::enqueue(int x){
    s1.push(x);
}
int QueuStack::dequeue(){
    int x = -1;
    if(s2.empty() && s1.empty())
        cout << "Queue is empty" << endl;
    else if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        x = s2.top();
        s2.pop();
    }
    else{
        x = s2.top();
        s2.pop();
    }
    return x;
}
void QueuStack::Display(){
    stack<int> d1 = s1;
    stack<int> d2 = s2;
    while(!d1.empty()){
            d2.push(d1.top());
            d1.pop();
        }
    while(!d2.empty()){
            cout << d2.top() << " ";
            d2.pop();
    }
    cout << endl;
}
int main(){
    QueuStack *Q;
    Q = new QueuStack();
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