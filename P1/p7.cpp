#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// p q k 
bool sortcol( const vector<ll>& v1,const vector<ll>& v2 ) {
 return v1[1] < v2[1];
}
  
void solve(){
    ll n, t1, t2;
    cin >> n;
    vector< vector<ll> > vec;
    for(ll i = 0; i < n; i++){
        cin >> t1 >> t2;
        vec.push_back({t1,t2});
    }
    sort(vec.begin(), vec.end(), sortcol);
    

}


int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--){
        solve();    
    }
	return 0;
}