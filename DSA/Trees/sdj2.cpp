#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    ll n, x, k; cin >> n >> x >> k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i= 0 ; i < n; i++) cin >> a[i];
    for(int i= 0 ; i < n; i++) cin >> b[i];
    ll count = 0;
    for(int i= 0 ; i < n; i++){
        if(abs(a[i] - b[i]) <= k)
            count++;
    }
    if(count < x){
        cout << "NO" << "\n";
    }
    else
        cout << "YES" << "\n";
    
    
    
}


int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}