#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve() {
    void solve() {
        ll n, k; cin >> n >> k;
        if (n % 2 == 0) {
            if (k > n / 2) {
                cout << -1 << "\n";
                return;
            }
        }
        else {
            if (k > n / 2 + 1) {
                cout << -1 << "\n";
                return;
            }
        }
        vector<vector<char> > vec(n, vector<char>(n, '.'));
        for (ll i = 0, j = 0;i < n && j < n;i += 2, j += 2) {
            if (k > 0) {
                vec[i][j] = 'R';
                k--;
            }
            else break;
        }
        for (ll i = 0;i < n;i++) {
            for (ll j = 0;j < n;j++) {
                cout << vec[i][j];
            }
            cout << "\n";
        }

        return;
    }
}


int main() {
    ll t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}