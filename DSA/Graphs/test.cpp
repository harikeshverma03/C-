#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll minPrime[10000001];
ll prevcount [10000001];
vector<ll> prime;
void sieve(ll n){
    memset(minPrime,0,sizeof(minPrime));
    for (ll i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    memset(prevcount,0,sizeof(prevcount));
    int size = 0;
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            prime.push_back(i);
            size++;
        }
        prevcount[i] = size;
    }
}

void solve(){
    ll n; cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(n <= 2){
        cout << 0 << "\n";
        return;
    }
    if(n == 3){
        cout << min({vec[2] - vec[1], vec[1] - vec[0], vec[2]-vec[0]}) << "\n";
        return;
    }
    ll l1=0,l2=0,ans=INT_MAX;
    for(int i = 1; i < n; i++){
        l1+=abs(vec[i]-vec[1+(n-1)/2]);
    }
    for(int i = 0; i < n-1; i++){
        l2+=abs(vec[i]-vec[(n-1)/2]);
    }
    ans=min(l1,l2);
    int low=1,high=n-2;
    while(low<high){
        ll temp = vec[high]-vec[0];
        ll po = vec[n-1]-vec[low];
        if(temp<po) low++;
        else high--;
        ans=min(ans,abs(temp-po)); 
    }
    cout << ans << "\n";
}  
int main() {
    IOS;
    int t;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
