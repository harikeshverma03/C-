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
ll MOD = 1e9 + 7;
double EPS = 1e-9;
const int mxn = 100001;

using namespace std;

ll minPrime[10000001];
vector<ll> primes;

void sieve(ll n) {
    memset(minPrime, 0, sizeof(minPrime));
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
            primes.pb(i);
        }
    }
}

vll facts[MAXN];
void sievefact(ll n) {
    for (ll i = 2;i <= n;i++) if (facts[i].size() == 0)
        for (ll j = i;j <= n;j += i) facts[j].pb(i);
}

vpll factorize(ll x) {
    vpll factors;
    unordered_map<ll, ll> m;
    m.clear();
    while (x != 1) {
        m[minPrime[x]]++;
        x /= minPrime[x];
    }

    for (auto i : m)
        factors.pb({ i.ff,i.ss });
    return factors;
}

void DBG() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if (sizeof...(t))
        cerr << ", ";
    DBG(t...);
}


ll extended_GCD(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_GCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

ll modinv(ll a, ll mod = MOD) {
    ll x, y, g;
    g = extended_GCD(a, mod, x, y);
    if (g != 1)
        return -1;
    else {
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
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}

ll max(ll a, ll b) {
    if (a > b) return a;
    return b;
}

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> vec;
    for (ll i = 0; i < n; i++) {
        vector<ll> temp(3);
        for (ll j = 0; j < 3; j++) cin >> temp[j];
        vec.push_back(temp);
    }
    vector<ll> ans(n, 0);
    priority_queue < pair<ll, vector<ll> >, vector<pair<ll, vector<ll>>>, greater<pair<ll, vector<ll>> > > left;
    priority_queue<pair<ll, vector<ll>>> right;
    ll lefti, righti, left_cost, right_cost;
    for (ll i = 0; i < n; i++) {

        pair<ll, vector<ll> > p, p1;
        left_cost = right_cost = INT_MAX;
        left.push({ vec[i][0], vec[i] });
        right.push({ vec[i][1], vec[i] });
        righti = right.top().first;
        while (!right.empty() && righti == right.top().first) {
            if (right_cost > right.top().second[2]) {
                p = right.top();
                right_cost = right.top().second[2];
            }
            right.pop();
        }
        right.push(p);
        lefti = left.top().first;
        while (!left.empty() && lefti == left.top().first) {
            if (left_cost > left.top().second[2]) {
                p1 = left.top();
                left_cost = left.top().second[2];
            }
            left.pop();
        }
        left.push(p1);
        if (p1.second[0] == p.second[0] && p1.second[1] == p.second[1])
            ans[i] = min(right_cost, left_cost);
        else if (p1.second[0] >= p.second[0] && p1.second[1] <= p.second[1])
            ans[i] = right_cost;
        else if (p1.second[0] <= p.second[0] && p1.second[1] >= p.second[1])
            ans[i] = left_cost;
        else
            ans[i] = right_cost + left_cost;
        //cout << left.top().second[0] << " " << left.top().second[1] << " " << left.top().second[2] << endl;
        //cout << right.top().second[0] << " " << right.top().second[1] << " " << right.top().second[2] << endl;
    }
    for (auto it : ans) {
        cout << it << "\n";
    }
}


int main() {
    IOS;
    ll t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}