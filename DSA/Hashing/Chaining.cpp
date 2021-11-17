#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct Node{
    public:
    int data;
    Node *next;
};
int Delete(Node *first,int pos){
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
Node* Search(Node *first, int key){
    Node *p = first;
    while (p)
    {
       if(key ==  p->data)
           return p;
       p = p->next; 
    }
    return NULL;
}

void InsertSort(struct Node **first,int x){
    struct Node *t,*q=NULL,*p=*first;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(*first == NULL){
        *first = t;
        return;
    }
    while (p){
        if(p->data > x){
            if(p==*first){
                t->next=*first;
                *first=t;
                return;
            }
            else{
                t->next = q->next;
                q->next = t;
                return;
            } 
        }
        q = p;
        p = p->next;
    }
    t->next = q->next;
    q->next = t;
    /*
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==*first){
        t->next=*first;
        *first=t;
    }
    else{
        t->next=q->next;
        q->next=t;
    }
    */
}
int hash1(int key){
    return key%10;
}
void Insert(struct Node *h[], int key){
    int index = hash1(key);
    InsertSort(&h[index], key);
}
int main(){
    struct Node* ht[10];
        for(int i = 0; i < 10; i++)
            ht[i] = NULL;
    Insert(ht, 12);
    Insert(ht, 22);

    struct Node* temp;
    temp = Search(ht[hash1(12)], 12);
    if(temp) cout << temp->data << endl;
    else cout << " Not found" << endl;
    return 0;
}
