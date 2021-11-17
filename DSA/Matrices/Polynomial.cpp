#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Term{
    public:
    int coef;
    int exp;
};
class Poly{
    public:
    int n;
    Term *t;
    
    Poly(int n){
        this->n = n;
        t = new Term[this->n];
    }
    ~Poly(){
        delete []t;
    }
    void display(){
        for(int i =0; i < n;i++){
            cout << t[i].coef << " " << t[i].exp << endl;
        }
    }
    int evaluate(int x){
        int sum = 0;
        for(int i =0; i < n;i++){
            sum = sum + t[i].coef*pow(x,t[i].exp);
        }
        return sum;
    }
    Poly Sum(Poly p2){
        int i,j,k;
        i = j= k= 0;
        Poly *p3;
        p3 = new Poly(n + p2.n);
        while(i < n && j < p2.n){
            if(t[i].exp == p2.t[j].exp){
                p3->t[k].exp = t[i].exp;
                p3->t[k++].coef = t[i++].coef + p2.t[j++].coef; 
            }
            else if(t[i].exp > p2.t[j].exp){
                p3->t[k++] = t[i++];
            }
            else {
                p3->t[k++] = p2.t[j++];
            }
        }
        for(;i < n; i++)
            p3->t[k++] = t[i++];
        for(;j < p2.n; j++)
            p3->t[k++] = p2.t[j++];
        return *p3;
    }
};

int main(){
    Poly *p;
    cout << "Enter the order of polynomial" << endl;
    int n;
    cin >> n; 
    p = new Poly(n);
    cout << "Enter Polynomial terms:" << endl;
    for(int i = 0; i < p->n; i++){
        cout << "Term number : " << i+1 << endl;
        int temp, temp1;
        cin >> temp>> temp1;
        p->t[i].coef = temp;
        p->t[i].exp = temp1;
    }
    p->display();
    Poly *p2;
    cout << "Enter the order of polynomial" << endl;
    int n2;
    cin >> n2; 
    p2 = new Poly(n2);
    cout << "Enter Polynomial terms:" << endl;
    for(int i = 0; i < p2->n; i++){
        cout << "Term number : " << i+1 << endl;
        int temp, temp1;
        cin >> temp>> temp1;
        p2->t[i].coef = temp;
        p2->t[i].exp = temp1;
    }
    cout << endl;


    
    Poly p3 = p2->Sum(*p);
    p3.display();
    int sum = p3.evaluate(5);
    cout << endl;
    cout << sum;
    return 0;
}