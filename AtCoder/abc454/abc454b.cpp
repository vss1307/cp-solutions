/*
 * Author: vss_1307
 * Created: 2026-04-18 17:31:18
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector <ll> v(m);
    bool ans = true;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v[x-1]++;
        if(v[x-1] == 2) ans = false;
    }
    cout << (ans? "Yes" : "No") << nl;
    ans = true;
    for(int i = 0; i < m; i++){
        if(!v[i]) ans = false;
    }
    cout << (ans? "Yes" : "No") << nl;
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