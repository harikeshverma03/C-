#include<iostream>
using namespace std;

int main(){
    int x,y;
    x = 10;
    y = 10;
    cout<<"Hello world!" << endl;
    cout<<"Hello world!" << endl;
}
void solve(){
    ll n; cin >> n;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++) cin >> vec[i];
    string s; cin >> s;
    vector<ll> po = vec;
    sort(all(po));
    bool got=true;
    for(ll i=0;i<n;i++){
        if(po[i]!=i+1) got=false;
    }
    if(got){
        cout << "YES" << "\n";
        return;
    }
    vector<ll> red,blue;
    for(ll i=0;i<n;i++){
        if(s[i]=='R') red.pb(vec[i]);
        else blue.pb(vec[i]);
    }
    sort(all(red));
    sort(all(blue));
    ll temp=1;
    for(ll i=0;i<blue.size();i++){
        if(blue[i]<temp){
            cout << "NO" << "\n";
            return;
        }
        temp++;
    }
    for(ll i=0;i<red.size();i++){
        if(temp<red[i]){
            cout << "NO" << "\n";
            return;
        }
        temp++;
    }
    cout << "YES" << "\n";
    return;
}

ll n; cin >> n;
    string s; cin >> s;
    if(n==1){
        cout << "SAHID" << "\n";
        return;
    }
    char c = s[0];
    vector<char> vec;
    for(ll i=1;i<n;i++){
        if(c==s[i]) continue;
        else{
            vec.pb(c);
            c=s[i];
        }
    }
    vec.pb(c);
    if(vec.size()==1){
        cout << "SAHID" << "\n";
        return;
    }
    if(vec.size()==2){
        cout << "RAMADHIR" << "\n";
        return;
    }
    if(vec.size()%3!=2){
        cout << "SAHID" << "\n";
    }
    else cout << "RAMADHIR" << "\n";