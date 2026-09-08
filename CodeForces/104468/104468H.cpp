/*
 * Author: vss_1307
 * Created: 2025-12-10 18:40:15
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector <ll> v(n), c(n);
    for(auto &x : v) cin >> x;
    for(auto &x : c) cin >> x;
    ll tot = 0;
    map <ll, ll> mp;
    map <ll, vector <ll> > mpc;
    for(int i = 0; i < n; i++){
        mpc[c[i]].push_back(v[i]);
    }
    for(auto &[x, y] : mpc){
        for(int i = 1; i < y.size(); i++) y[i] += y[i-1];
    }
    ll q; cin >> q;
    while(q--){
        ll t, col, x; cin >> t >> col >> x;
        switch(t){
            case 1: 
                tot += x;
                mp[col] -= x;
                break;
            case 2: 
                ll l = -1, r = mpc[col].size();
                while(r-l>1){
                    ll mid = (r + l) >> 1;
                    if(mpc[col][mid] + (mid + 1) * (tot + mp[col]) <= x) l = mid;
                    else r = mid;
                }
                cout << l+1 << nl;
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    // int te; cin >> te;
    // while (te--)
        solve();
}