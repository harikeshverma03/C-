#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll maxx=a[i],minn=a[i];
        set<ll> s;
        for(ll j=i;j<n;j++){
            s.insert(a[j]);
            maxx=max(maxx,a[j]);
            minn=min(minn,a[j]);
            if(j-i<2)
                continue;
            ll val=0;
            auto pos=s.lower_bound((maxx+minn)/2);
            if(pos!=s.end()){
                val=max(val,(maxx-*(pos))*((*pos)-minn));
            }
            if(pos!=s.begin()){
                pos--;
                val=max(val,(maxx-*(pos))*((*pos)-minn));
            }
            ans+=val;
        }

    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}