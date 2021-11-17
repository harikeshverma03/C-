#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class LinkedList{
    public:
    Node *first;
    Node *last;
    LinkedList(){
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList(){}
    void Display();
    void DisplayR(Node*p);
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
    int Count();
    int Sum();
    int Max();
    Node* Search(int key);
    Node* SearchR(Node *p, int key);
    Node* SearchT(int key);
    void Insert(LinkedList *l, int index, int x);
    void InsertLast(int x);
    void InsertSort(int x);
    bool Issorted();
    void RemoveDup();
    void ReverseEle(LinkedList *l);
    void ReverseLinks();
    void Reverserec(Node*p, Node*q);
    
    bool IsLoop();
    Node* Concatenation(LinkedList*second);
    Node* Merge(LinkedList*second);
    Node* MiddleElement();
};

Node* LinkedList::MiddleElement(){
    Node*p = first, *q = first;
    q = q->next->next;
    while(q != NULL){
        p = p->next;
        q = !q->next ? NULL :  q = q->next->next;
           
    }
    return p;
}
bool LinkedList::IsLoop(){
    Node*p;
    Node*q;
    p = q = first;
    while(p && q){
        //cout << p->data << " ";
        p = p->next;
        q = q->next;
        q = (q!=NULL)?q->next: NULL;
        if(p == q) 
            return true;
    }
    return false;
}
void LinkedList::ReverseLinks(){
    Node*p = first;
    Node*q = NULL;
    Node*r = NULL;
    while(p!= NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first =q;
}
bool LinkedList::Issorted(){
    Node*p = first;
    int prev = p->data;
    p = p->next;
    while(p != NULL){
        if (p->data < prev)
            return false;
        prev = p->data;
        p = p->next;
    }
    return true;
}
void LinkedList::RemoveDup(){
    Node*p = first;
    Node*q = NULL;
    int prev = p->data;
    q = p;
    p = p->next;
    
    while(p != NULL){
        if (p->data == q->data){
            q->next = p->next;
            delete p;
            p = q->next;
        }
        else{
            q = p;
            p = p->next;
        }
    }
}
int LinkedList::Delete(int pos){
    Node*p,*q;
    p = first;
    q = NULL;
    int x = -1;
    if(pos==0){
        first = first->next;
        x = p->data;
        delete p;
    }
    else{
        for(int i = 0; i < pos - 1 && p!=NULL ; i++){
            q = p;
            p = p->next;
        }
        if(p!= NULL){
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}
void LinkedList::InsertSort(int x){
    Node * t = new Node;
    t->data = x;
    if(first == NULL){
        t->next = NULL;
        first = t;
        return;
    }
    Node *p;
    Node *q;
    p = first;
    while (p){
        if(p->data >= x){
            t->next = q->next;
            q->next = t;
            return;
        }
        q = p;
        p = p->next;
    }
    q->next = t;
    t->next = NULL;
}
void LinkedList::InsertLast(int x){
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first  = last = t;
    else{
        last->next = t;
        last = t;
    }
}
void LinkedList::DisplayR(Node *p){
    if (p!= NULL){
        cout << p->data << " ";
        DisplayR(p->next);
    }
    else 
        cout << endl;
}
LinkedList::LinkedList(int A[], int n){
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void LinkedList::Display(){
    Node *p = first;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int LinkedList::Count(){
    int count = 0;
    Node *p = first;
    while (p){
        count++;
        p = p->next;
    }
    return count;
}
int LinkedList::Sum(){
    int sum = 0;
    Node*p = first;
    while (p)
    {
        sum+=p->data;
        p = p->next;
    }
    return sum;
    
}
int LinkedList::Max(){
    Node *p = first;
    int max = first->data;
    p = p->next;
    while (p){
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
Node* LinkedList::Search(int key){
    Node *p = first;
    while (p)
    {
       if(key ==  p->data)
           return p;
       p = p->next; 
    }
    return NULL;
}
Node* LinkedList::SearchR(Node *p, int key){
    if(p==NULL)
        return NULL;
    if(key == p->data)
        return p;
    else
        return SearchR(p->next, key);
}
Node* LinkedList::SearchT(int key){
    Node *p = first;
    Node *q = NULL;
    while (p)
    {
       if(key ==  p->data){
           q->next = p->next;
           p->next = first;
           first = p;
           return p;
       }
       q = p; 
       p = p->next; 
    }
    return NULL;
}
void LinkedList::Insert(LinkedList *l, int index, int x){
    Node *t;
    if(index < 0 || index > l->Count())
        return;
    t = new Node;
    t->data = x;
    if (index == 0){
        t->next = l->first;
        l->first = t;
    }
    else{
        Node*p = l->first;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t; 
    }
}
void LinkedList::ReverseEle(LinkedList *l){
    int*A;
    A = new int(l->Count());
    Node*p = l->first;
    int i = 0;
    while(p!=NULL){
        A[i++] = p->data;
        p = p->next;
    }
    p = l->first;
    i--;
    while(p!=NULL){
        p->data = A[i--];
        p = p->next;
    }
}
void LinkedList::Reverserec(Node*p, Node*q){
    if(p!=NULL){
        cout << p->data << " ";
        Reverserec(p->next, p);
        cout << p->data << " ";
        p->next = q;
    }
    else{
        first = q;
        return;
    }   
}
Node*LinkedList::Concatenation(LinkedList*second){
    Node*p = first;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = second->first;
    return first;
}
Node* LinkedList::Merge(LinkedList*second){
    Node*third;
    Node*last;
    if(first->data < second->first->data){
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        third = last = second->first;
        second->first = second->first->next;
        last->next = NULL;
    }
    while(first != NULL && second->first != NULL){
        cout << last->data << " ";
        if(first->data < second->first->data){
        last->next = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        last->next = second->first;
        last = second->first;
        second->first = second->first->next;
        last->next = NULL;
    }
    }
    if(first!=NULL)
        last->next = first;
    else
        last->next = second->first;
    return third;
}
int main(){
    LinkedList *first;
    LinkedList *second;
    LinkedList *third;
    //int A[] = {3,5,7,9,11,15};
    //first = new LinkedList(A, 6);
    //first->Display();
    first = new LinkedList();
    second = new LinkedList();
    third = new LinkedList();
    first->InsertSort(5);
    first->InsertSort(10);
    first->InsertSort(11);
    first->InsertSort(12);
    first->InsertSort(15);
    first->InsertSort(16);
    //first->InsertSort(18);
    first->DisplayR(first->first);

    second->InsertLast(6);
    second->InsertLast(9);
    second->InsertLast(13);
    second->InsertSort(25);
    second->InsertSort(20);
    second->InsertSort(17);
    second->InsertSort(30);
    second->DisplayR(second->first);
    third->first = first->Concatenation(second);
    
    cout << third->MiddleElement()->data << endl;
    third->Display();

    Node* t1, *t2;
    t2 = third->first;
    t1 = third->first->next->next->next;
    
    while(t2->next !=NULL){
        //cout << t2->data << " ";
        t2 = t2->next;}
    cout << t2->data << endl;



    t2->next = t1;
    cout << third->IsLoop() << endl;
    //third->Display();
    return 0;
}
    /*
    cout << first->Sum() << endl;
    cout << first->Count() << endl;
    cout << first->Max() << endl;
    Node *p = first->Search(12);
    //cout << p->data << endl;
    //cout << "Niharika" << endl;
   // p = first->SearchR(first->first, 9);
    //cout << p->data << endl;
    //cout << "Niharika" << endl;
    p = first->SearchT(53);
    if(p != NULL)
        cout << "Key is found:" << endl;
    else
        cout << "Key is not found" << endl;
    //cout << "Niharika" << endl;
    //cout << first->Delete(0) << endl;
    first->Reverserec(first->first,NULL);
    first->Display();
    first->ReverseEle(first);
    
    first->ReverseLinks();
    first->Display();
    
    cout << endl;
    
    first->Reverserec(first->first,NULL);
    cout << endl;
    first->Display();
    
    return 0;
}
*/