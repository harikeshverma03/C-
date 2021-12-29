#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define ar array
#define mxx 1e9
using namespace std;

class account{
    public:
    map<string, pair<int,int> > mp;
    account(){};
    void credit(string in,string id);
    void debit(string in,string id);
    void check_balance(string id);
    void create_user(string id);
    void transfer(string in1, string id1, string id2);
};

pair<int,int> string_int(string in){
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
    return {dol,cent};
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

void account:: credit(string in,string id){
    if(mp.find(id) == mp.end()){
        cout << "User does not exist \n please try again \n";
        return;
    }
    pair<int,int> p = string_int(in);
    int dol = p.first;
    int cent = p.second;
    pair<int,int> q = mp[id];
    q.first+=dol;
    q.second+=cent;
    q.first+=(q.second/100);
    q.second%=100;
    if(q.first<0 && q.second>0){
        q.first+=1;
        q.second-=100;
    }
    else if(q.first>0 && q.second<0){
        q.first-=1;
        q.second+=100;
    }
    if(q.first > mxx){
        cout << "The Maximum amount has been reached" << "\n";
        return;
    }
    mp[id] = q;
    cout << "Succesful!" << "\n";
    return;
}

void account:: debit(string in,string id){
    if(mp.find(id) == mp.end()){
        cout << "User does not exist \n please try again \n";
        return;
    }
    pair<int,int> p = mp[id];
    if(p.first < 0 || p.second < 0){
        cout << "You don't have enough balance to complete this transaction" << "\n";
        return;
    }
    pair<int,int> q = string_int(in);
    p.first-=q.first;
    p.second-=q.second;
    if(p.first<0 && p.second>0){
        p.first+=1;
        p.second-=100;
    }
    else if(p.first>0 && p.second<0){
        p.first-=1;
        p.second+=100;
    }
    p.first+=(p.second/100);
    p.second%=100;
    mp[id] = p;
    cout << "Succesful!" << "\n";
    return;
}

void account::check_balance(string id){
    if(mp.find(id) == mp.end()){
        cout << "User does not exist \n please try again \n";
        return;
    }
    pair<int,int> p = mp[id];
    cout << p.first << "D" << " " << p.second << "C" << "\n";
    return;
}

void account:: create_user(string id){
    if(mp.find(id) != mp.end()){
        cout << "User already exist \n please try again \n";
        return;
    }
    cout << "Enter the intial deposit: ";
    //cin.ignore(256, '\n');
    string str;
    getline(cin, str);
    cout << str << endl;
    pair<int, int> p = string_int(str);
    mp[id] = p;
    return;
}
void account:: transfer(string in1, string id1, string id2){
    debit(in1, id1);
    credit(in1, id2);
    cout << "Succesfull" << "\n";
}
int main(){
    string menu = "1. credit \n 2.debit \n 3.Check Balance \n 4. Create new user \n 5. Transfer money \n 6.exit";
    int choice = 1;
    account mine;
    mine.mp["hari"] = {0, 0};
    while(true){
        string inp;
        cout << menu << "\n";
        cin >> choice;
        if(choice == 1){
            cout << "Enter amount:";
            cin.ignore(256, '\n');
            getline(cin, inp);
            cout << "Enter your user id: ";
            string id;
            //cin.ignore(256, '\n');
            getline(cin, id);
            mine.credit(inp, id);
        }
        else if(choice == 2){
            cout << "Enter amount:";
            cin.ignore(256, '\n');
            getline(cin, inp);
            cout << "Enter your user id: ";
            string id;
            //cin.ignore(256, '\n');
            getline(cin, id);
            mine.debit(inp, id);
        }
        else if(choice == 3){
            cout << "Enter your user id: ";
            string id;
            cin.ignore(256, '\n');
            getline(cin, id);
            mine.check_balance(id);
        }
        else if(choice == 4){
            cout << "Enter your name:";
            cin.ignore(256, '\n');
            getline(cin, inp);
            mine.create_user(inp);
        }
        else if(choice == 5){
            cout << "Enter the amount to be transferred: ";
            cin.ignore(256, '\n');
            string id1, id2;
            getline(cin, inp);
            cout << "Enter your id: ";
            getline(cin, id1);
            cout << "Enter reciever's id: ";
            getline(cin, id2);
            mine.transfer(inp, id1, id2);
        }
        else if(choice == 6){
            cout << "Thank you!" << endl;
            break;
        }
        else{
            cout << "Invalid choice \n Please try again \n" ;
        }
    } 
    return 0;
}