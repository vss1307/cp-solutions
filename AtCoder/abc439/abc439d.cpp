/*
 * Author: vss_1307
 * Created: 2026-01-03 17:57:13
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    map < ll, array<vector <ll>, 3> > mp;
    for(int i = 0; i < n; i++){
        if(v[i] % 3 == 0) mp[v[i]/3][2].push_back(i);
        else if(v[i] % 5 == 0) mp[v[i]/5][1].push_back(i);
        else if(v[i] % 7 == 0) mp[v[i]/7][0].push_back(i);   
    }
    ll ans = 0;
    for(auto &[x, a] : mp){
        for(int i = 0; i < a[1].size(); i++){
            int p = a[0].end() - upper_bound(a[0].begin(), a[0].end(), a[1][i]);
            int q = a[2].end() - upper_bound(a[2].begin(), a[2].end(), a[1][i]);
            ans += p * 1ll * q;
        }
        for(int i = 0; i < a[2].size(); i++){
            int p = upper_bound(a[0].begin(), a[0].end(), a[2][i]) - a[0].begin();
            int q = upper_bound(a[1].begin(), a[1].end(), a[2][i]) - a[1].begin();
            ans += p * 1ll * q;
        }
    }
    cout << ans << nl;
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