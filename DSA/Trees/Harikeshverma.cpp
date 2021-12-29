#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define ar array
#define mxx 1e9
using namespace std;

class account{
    double balance;
    public:
    account(){
        balance = 0.0;
    };
    void Credit(string in);
    void Debit(string in);
    void Check_bal();
};
double string_int(string in){
    int n = in.size();
    int dol = 0, cent = 0, i;
    for(i = 0; i < n; i++){
        if(in[i] == 'D'){
            dol = stoi(in.substr(0, i));
            break;
        }
        if(in[i] == 'C'){
            cent = stoi(in.substr(0, i));
            break;
        }
    }
    if(i < n-1)cent = stoi(in.substr(i+2, n-2));
    dol = dol + cent/100;
    cent = cent %100;
    double c = dol + (double)cent/100;
    return c;
}
void int_string(double in){
    if(in < 0){
        cout << "- ";
        in = -in;
    }
    cout << int(in) << "D ";
    cout << int(in *100) %100  << "C ";
    cout << endl;
}
void account:: Credit(string in){
    if(balance > mxx){
        cout << "The Maximum amount has been reached" << endl;
        return;
    }
    double cred = string_int(in);
    balance = balance + cred;
    cout << "Succesful!" << endl;
}
void account:: Debit(string in){
    if(balance < 0.0){
        cout << "You don't have enough balance to complete this transaction" << endl;
        return;
    }
    double cred = string_int(in);
    balance = balance - cred;
    cout << "Succesful!" << endl;
}
void account::Check_bal(){
    cout <<"current Balane is: " ;
    int_string(balance);
}
int main(){
    string menu = "1. Credit \n 2.Debit \n 3.Check Balance \n 4. exit";
    int choice = 1;
    account mine;
    while(true){
        string inp;
        cout << menu << "\n";
        cin >> choice;
        if(choice == 1){
            cout << "Enter amount:";
            cin.ignore(256, '\n');
            getline(cin, inp);
            mine.Credit(inp);
        }
        else if(choice == 2){
            cout << "Enter amount:";
            cin.ignore(256, '\n');
            getline(cin, inp);
            mine.Debit(inp);
        }
        else if(choice == 3){
            mine.Check_bal();
        }
        else if(choice == 4){
            cout << "Thank you!" << endl;
            break;
        }
        else{
            cout << "Invalid choice \n Please try again \n" ;
        }
    } 
    return 0;
}

