#include<bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#define ll long long int
#define ar array
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define pll ar<ll,2> 
#define vpll vector<pll>
#define pb push_back
#define ff first
#define ss second
#define ok order_of_key
#define fo find_by_order
#define LCM(a,b) (a*(b/__gcd(a,b)))
#define all(v) v.begin(),v.end()
#define lb(v,val)  (lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (upper_bound(v.begin(),v.end(),val)-v.begin())
#define INF (ll) 1e18
#define NEGINF -INF
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ini(a,b) memset(a,b,sizeof(a))
#define vvll vector<vector<ll>>
#define vt vector
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MEM(a, b) memset(a, b, sizeof(a))
#define MAXN (int)(1 * 1e6 + 10)
#define prec(n) fixed<<setprecision(n)
#define each(x, a) for (auto& x: a)
#define F_OR(i, a, b, s) for (ll i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(_VA_ARGS_, F_OR4, F_OR3, F_OR2, F_OR1)
#define forn(...) F_ORC(_VA_ARGS)(VA_ARGS_)
#define pi 3.141592653589793238
#define google() cout << "Case #" << i << ": ";
ll MOD=1e9+7;
double EPS = 1e-9;
const int mxn = 100001;

using namespace std;

ll minPrime[10000001];
vector<ll> primes;

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
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            primes.push_back(i);
        }
    }
}

vll facts[MAXN];
void sievefact(ll n){
    for(ll i=2;i<=n;i++) if(facts[i].size()==0)
      for(ll j=i;j<=n;j+=i) facts[j].pb(i);
}

vpll factorize(ll x){
    vpll factors;
    unordered_map<ll,ll> m;
    m.clear();
    while (x != 1) {
        m[minPrime[x]]++;
        x /= minPrime[x];
    }
 
    for(auto i:m)
        factors.pb({i.ff,i.ss});
    return factors;
}

void DBG() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}


ll extended_GCD(ll a , ll b , ll &x , ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b % a , a , x1 , y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modinv(ll a , ll mod = MOD) {
    ll x , y, g;
    g = extended_GCD(a , mod , x , y);
    if (g != 1)
        return -1;
    else{
        if (x < 0) x += mod;
        return x;
    }
}

ll binpow(ll x, ll y, ll p)
{
    int res = 1;  
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll min(ll a,ll b){
    if(a<b) return a;
    return b;
}

ll max(ll a,ll b){
    if(a>b) return a;
    return b;
}
ll mod = 1e9 + 7;
vector<ll> fact(44730, 0);

void facto(){
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    for(int i = 3; i < fact.size(); i++)
        fact[i] = (i * fact[i-1])%mod;
}
vector<ll> row(ll num){
    vector<ll> vec(num+1);
    for(int i = 0; i < vec.size(); i++){
        vec[i] = ((fact[num])/(fact[i] * fact[num-i]))%mod;
    }
    return vec;
}
void solve(){
    ll s, e; cin >> s >> e;
    if(s == e){
        cout << 0 << "\n";
        return;
    }
    int start_y = 0, count = 1;
    while(start_y + count < s){
        start_y++;
        count+=start_y;
    }
    int start_x = s - count;
    int end_y = 0; count = 1;
    while(end_y + count < e){
        end_y++;
        count+=end_y;
    }
    int end_x = e - count;
    if(start_x > end_x || start_y > end_y){
        cout << 0 << "\n";
        return;
    }
    //cout << end_y << " " << start_y << endl;
    vector<ll> end = row(end_y - start_y);
   // cout << end_y << " " << start_y << endl;
    ll des = end_x-start_x;

    if(des >= end.size()){
        cout << 0 << "\n";
        return;
    }  
    else{
        cout << end[des]%(ll)(1e9+7) << "\n";
        return;
    }


}
    /*
    queue<pair<int, int>> q;
    map<pair<int, int>, ll> mp;
    q.push({start_x, start_y});
    mp[{start_x, start_y}] = 1;
    ll mod = 1e9 + 7;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        if(p.first <= end_x && p.second+1 <= end_y){
            if(mp.find({p.first, p.second+1}) == mp.end())
                q.push({p.first, p.second+1});
            mp[{p.first, p.second+1}] =(mp[{p.first, p.second+1}]+ mp[p])%mod;
        }
        if(p.first+1 <= end_x && p.second+1 <= end_y){
            if(mp.find({p.first + 1, p.second + 1}) == mp.end())
                q.push({p.first + 1, p.second + 1});
            mp[{p.first+1, p.second+1}]=(mp[{p.first+1, p.second+1}] + mp[p])%mod;
        }
    }
    cout << mp[{end_x, end_y}]%mod << "\n";
}
*/
int main(){
    IOS;
    facto();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}