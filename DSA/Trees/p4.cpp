#include<bits/stdc++.h>
#include<string.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#define ll long long int
#define ar array
#define mxx 1e9
using namespace std;

class account{
    pair<int,int> balance;
    public:
    account();
    void Credit(string in);
    void Debit(string in);
    void Check_bal();
};

pair<int,int> comp(string in){
    int n = in.size();
    int l1=0,l2=0;
    for(int i=0;i<n;i++){
        if(in[i]=='D') l1=i;
        else if(in[i]=='C') l2=i;
    }
    int dollar = stoi(in.substr(0,l1));
    int cent = stoi(in.substr(l1+2,n-l1-2));
    while(cent>100){
        cent-=100;
        dollar++;
    }
    return {dollar,cent};
}

void account:: Credit(string in){
    pair<int,int> p = comp(in);
    balance.first+=p.first;
    balance.second+=p.second;
    cout << "Succesful!" << endl;
}

void account:: Debit(string in){
    if(balance.first < 0){
        cout << "You don't have enough balance to complete this transaction" << endl;
        return;
    }
    pair<int,int> cred = comp(in);
    balance.first = balance.first - cred.first;
    balance.second = balance.second - cred.second;
    cout << "Succesful!" << endl;
}
void account::Check_bal(){
    
}

int main(){
    string menu = "1. Credit \n 2.Debit \n 3.Check Balance \n 4. exit";
    int choice = 1;
    account mine;
    while(choice){
        string inp;
        cout << menu << "\n";
        cin >> choice;
        if(choice == 1){
            cout << "Enter amount:" << endl;
            cin >> inp;
            mine.Credit(inp);
        }
        if(choice == 2){
            cout << "Enter amount:" << endl;
            cin >> inp;
            mine.Debit(inp);
        }
        if(choice == 3){
            mine.Check_bal();
        }
        if(choice == 4){
            cout << "Thank you!" << endl;
            break;
        }
        else{
            cout << "Invalid choice \n Please try again" << endl;
        }
    } 
    return 0;
}