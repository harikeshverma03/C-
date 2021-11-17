#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(){
        lchild = rchild = NULL;
    }
    Node(int x){
        data = x;
        lchild = rchild = NULL;
    }
};
class Binarytree{
    Node *root;
    public:
    
    Binarytree(){
        root = NULL;
    }
    Binarytree(int x){
        root->lchild = root->rchild = NULL;
        root->data = x;
    }
    void Create();
    void preOrder(){preOrder(root);}
    void preOrder(Node *r);
    
    void inOrder(Node *r);
    void inOrder(){inOrder(root);}

    void postOrder(Node *r);
    void postOrder(){postOrder(root);}

    void levelOrder();
    
    int Height(Node *r);
    int Height(){return Height(root);}

    void InOrderit();
    void PreOrderit();
    void PostOrderit();
    int Count(Node *r);
    int Count(){return Count(root);}

    int Count0(Node *r);
    int Count0(){return Count0(root);}

    int Count1(Node *r);
    int Count1(){return Count1(root);}

    int Count2(Node *r);
    int Count2(){return Count2(root);}

    int Countin(Node *r);
    int Countin(){return Countin(root);}

};
void Binarytree::Create(){
    Node *p, *t;
    int x;
    queue<Node*> q;
    //cout << "Enter root value: ";
    cin >> x;
    root = new Node(x);
    q.push(root);
    while(!q.empty()){
        p = q.front();
        q.pop();
        //cout << "Enter left child value of " << p->data << ": ";
        cin >> x;
        if(x){
            t = new Node(x);
            p->lchild = t;
            q.push(t);
        }
        //cout << "Enter right child value of  " << p->data << ": ";
        cin >> x;
        if(x){
            t = new Node(x);
            p->rchild = t;
            q.push(t);
        }
    }
}
void Binarytree::preOrder(Node *r){
    if (r){
        cout << r->data << " ";
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}
void Binarytree::inOrder(Node *r){
    if (r){
        inOrder(r->lchild);
        cout << r->data << " ";
        inOrder(r->rchild);
    }
}
void Binarytree::postOrder(Node *r){
    if (r){
        postOrder(r->lchild);
        postOrder(r->rchild);
        cout << r->data << " ";
    }
}
void Binarytree::levelOrder()
{
    Node *r = root;
    queue<Node*> q;
    printf("%d ",r->data);
    q.push(r);
    while(!q.empty())
    {
        r=q.front();
        q.pop();
        if(r->lchild){
            printf("%d ",r->lchild->data);
            q.push(r->lchild);
        }
        if(r->rchild){
            printf("%d ",r->rchild->data);
            q.push(r->rchild);
        }
    }
}
int Binarytree::Height(Node *r)
{
    if(r)
        return max(Height(r->lchild),Height(r->rchild)) + 1;
    return 0;
}


void Binarytree::PreOrderit(){
    stack<Node*> s;
    Node *t = root;
    while(t || !s.empty()){
        if(t){
            cout << t->data <<" ";
            s.push(t);
            t = t->lchild;
        }
        else{
            t = s.top();
            s.pop();
            t = t->rchild;
        }
    }
}


void Binarytree::InOrderit(){
    stack<Node *> s;
    Node *t = root;
    while(t|| !s.empty()){
        if(t){
            s.push(t);
            t = t->lchild;
        }
        else{
            t = s.top();
            s.pop();
            
            cout << t->data <<" ";
            t = t->rchild;
        }
    }
}
void Binarytree::PostOrderit(){
    stack<ll> s;
    ll temp;
    Node *t = root;
    while(t || !s.empty()){
        if(t){
            s.push((ll)t);
            t = t->lchild;
        }
        else if (t == NULL){
            temp = s.top();
            s.pop();
            if(temp > 0){
                s.push(-temp);
                t = (Node*)temp;
                t = t->rchild;
            }
            else{
                temp = -temp;
                t = (Node*)temp;
                cout << t->data << " ";
                t = NULL;
            }
        }
    }
}
int Binarytree::Count(Node *r){
    if(r)
        return Count(r->lchild) + Count(r->rchild) + 1;
    return 0;
}
int Binarytree::Count0(Node *r){
    if(r == NULL)
        return 0;
    if(r->rchild == NULL && r->lchild == NULL)
        return  Count0(r->lchild) + Count0(r->rchild) + 1;
    else 
        return Count0(r->lchild) + Count0(r->rchild) ;
    return 0;
}
int Binarytree::Count1(Node *r){
    if(r == NULL)
        return 0;
    if(r->rchild != NULL ^ r->lchild != NULL)
        return  Count1(r->lchild) +Count1(r->rchild) + 1;
    else 
        return Count1(r->lchild) +Count1(r->rchild);
    return 0;
}
int Binarytree::Count2(Node *r){
    if(r == NULL)
        return 0;
    if(r->rchild != NULL && r->lchild != NULL)
        return  Count2(r->lchild) + Count2(r->rchild) + 1;
    else 
        return Count2(r->lchild) + Count2(r->rchild);
    return 0;
}
int Binarytree::Countin(Node *r){
    if(r == NULL)
        return 0;
    if(r->rchild != NULL || r->lchild != NULL)
        return  Countin(r->lchild) + Countin(r->rchild) + 1;
    else 
        return Countin(r->lchild) + Countin(r->rchild);
    return 0;
}
int main(){
    Binarytree bt;
    bt.Create();
    bt.preOrder();
    cout << "\n" ;
    bt.PreOrderit();
    cout << "\n"; 
    bt.inOrder();
    cout << "\n"; 
    bt.InOrderit();
    cout << "\n";
    bt.postOrder();
    cout << "\n" ;
    bt.PostOrderit();
    cout << "\n"; 
    cout << bt.Height() << endl;
    cout << bt.Count() << endl;
    cout << bt.Count0() + bt.Count1() + bt.Count2() << endl;
    cout << bt.Countin() << endl;
    return 0;
}