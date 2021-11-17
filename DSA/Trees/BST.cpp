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
    class BST{
        public:
        Node *root;
        BST(){
            root = NULL;
        }
        void Insert(int key);
    Node* RInsert(Node*r, int key);
    Node* Search(int key);
    Node* RSearch(Node *r, int key);
    vector<int> InOrder();
    vector<int> PreOrder();
    vector<int> PostOrder();
    Node *Delete(Node *r, int key);
    int Height(Node *r);
    Node *InPre(Node *r);
    Node *InSuc(Node *r);
    void CreatePre(vector<int>);
    void CreatePost(vector<int>);
};
void BST::Insert(int key){
    if(root == NULL){
        root = new Node(key);
        return;
    }
    Node*t = root, *r = NULL, *p;
    while(t != NULL){
        r = t;
        if(key == t->data)
            return;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    p = new Node(key);
    if(key < r->data)
        r->lchild = p;
    else 
        r->rchild = p;
}

Node* BST::RInsert(Node*r, int key){
    if(r == NULL){
        Node *p = new Node(key);
        return p;
    }
    if (key < r->data)
        r->lchild = RInsert(r->lchild, key);
    else if (key > r->data)
        r->rchild = RInsert(r->rchild, key);
    return r;
}


Node* BST::Search(int key){
    Node *t = root;
    while(t != NULL){
        if(key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

Node *BST::RSearch(Node *r, int key){
    if(!r) return NULL;
    if (key == r->data)
        return r;
    else if (key < r->data)
        return RSearch(r->lchild, key);
    else 
        return RSearch(r->rchild, key);
}

vector<int> BST::InOrder(){
    vector<int> vec;
    stack<Node *> st;
    Node *t = root;
    while(t || !st.empty()){
        if(t){
            st.push(t);
            t = t->lchild;
        }
        else {
            t = st.top();
            vec.push_back(t->data);
            st.pop();
            t = t->rchild;
        }
    }
    return vec;
}

vector<int> BST::PreOrder(){
    vector<int> vec;
    stack<Node *> st;
    Node *t = root;
    while(t || !st.empty()){
        if(t){
            st.push(t);
            vec.push_back(t->data);
            t = t->lchild;
        }
        else {
            t = st.top();
            st.pop();
            t = t->rchild;
        }
    }
    return vec;
}

vector<int> BST::PostOrder(){
    vector<int> vec;
    stack<ll> st;
    Node *t = root;
    while(t || !st.empty()){
        if(t){
            st.push((ll)t);
            t = t->lchild;
        }
        else {
            ll temp = st.top();
            st.pop();
            if (temp > 0){
                t = (Node *)temp;
                st.push(-temp);
                t = t->rchild;
            }
            else if (temp < 0){
                temp = -temp;
                t = (Node *)temp;
                vec.push_back(t->data);
                t = NULL;
            }
            
        }
    }
    return vec;
}


int BST::Height(Node *r)
{
    if(r)
        return max(Height(r->lchild),Height(r->rchild)) + 1;
    return 0;
}
Node *BST::Delete(Node *r, int key){
    if (!r) return NULL;
    if(r->lchild == NULL && r->rchild == NULL && r->data == key){
        if(r == root)
            root = NULL;
        delete r;
        return NULL;
    }
    
    if (key < r->data)
        r->lchild = Delete(r->lchild, key);
    else if (key > r->data)
        r->rchild = Delete(r->rchild, key);
    else{
        if(Height(r->lchild) >Height(r->lchild)){
            Node *q = InPre(r->lchild);
            r->data = q->data;
            r->lchild = Delete(r->lchild, q->data);
        }
        else {
            Node*q = InSuc(r->rchild);
            r->data = q->data;
            r->rchild = Delete(r->rchild, q->data );
        }
    }
    return r;
}
Node *BST::InPre(Node *r){
    while(r && r->rchild)
        r = r->rchild;
    return r;
}


Node *BST::InSuc(Node *r){
    while(r && r->lchild)
        r = r->lchild;
    return r;
}
bool PreValidate(vector<int> pre);
void BST::CreatePre(vector<int> pre){
    if(!PreValidate(pre)){
        root = NULL;
        return;
    }
    int n = pre.size();
    stack<Node*> st;
    root =  new Node(pre[0]);
    Node *p = root, *t;
    st.push(root);
    int i = 1;
    while(i < n){
        if(pre[i] < p->data){
            t = new Node(pre[i++]);
            p->lchild = t;
            st.push(p);
            p = t;
        }
        else{
            int temp;
            if(st.empty())
                temp = INT_MAX;
            else temp = st.top()->data;
            if(pre[i] < temp){
                t = new Node (pre[i++]);
                p->rchild = t;
                p = t;
            }
            else {
                p = st.top();
                st.pop();
            }
        }
    }
}

void BST::CreatePost(vector<int> pre){
    int n = pre.size();
    stack<Node*> st;
    root =  new Node(pre[n-1]);
    Node *p = root, *t;
    st.push(root);
    int i = n-2;
    while(i >= 0){
        if(pre[i] > p->data){
            t = new Node(pre[i--]);
            p->rchild = t;
            st.push(p);
            p = t;
        }
        else{
            int temp;
            if(st.empty())
                temp = -INT_MAX;
            else temp = st.top()->data;
            if(pre[i] > temp){
                t = new Node (pre[i--]);
                p->lchild = t;
                p = t;
            }
            else {
                p = st.top();
                st.pop();
            }
        }
    }
}
bool PreValidate(vector<int> pre){
        int lower=-1;
        stack<int> s;
        for(long int i=0;i<pre.size();i++)
        {
            if(lower>-1 && pre[i] < lower)
            {
                lower=-2;
                break;
            }
            while(!s.empty() && s.top()<pre[i])
            {
                lower =s.top();
                s.pop();
            }
            s.push(pre[i]);
        }
        if(lower==-2)
        return false;
        else
        return true;
    }

int main(){
    vector<int> vec;
    BST bt;
    bt.root = NULL;
    bt.Insert(30);
    bt.Insert(20);
    bt.Insert(10);
    bt.Insert(15);
    bt.Insert(25);
    bt.Insert(40);
    bt.Insert(50);
    bt.root = bt.Delete(bt.root, 50);
    cout << ((bt.RSearch(bt.root, 22) != NULL) ? bt.RSearch(bt.root, 22)->data : -1) << endl;
    vec = bt.PreOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;
    vec = bt.PostOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;
    vec = bt.PreOrder();


    BST bt1;
    bt1.root = NULL;
    bt1.CreatePre({2,3,1,5});
    if(bt1.root == NULL) cout << "not made" << endl;
    vec = bt1.PreOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;
    vec = bt1.PostOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;

    BST bt2;
    bt2.root = NULL;
    bt2.CreatePost(vec);
    vec = bt2.PreOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;
    vec = bt2.PostOrder();
    for(int po :vec)
        cout << po << " ";
    cout << endl;

    return 0;
}