/*
 * Author: vss_1307
 * Created: 2025-12-25 21:57:06
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
    vector <string> v(n);
    for(auto &x : v) cin >> x;
    vector <vector <ll> > paths(n, vector <ll>(n, -1));
    auto dfs = [&](ll i, ll j, auto &self)->ll{
        if(i == n || j == n || v[i][j] == '*') return 0;
        if(i == n-1 && j == n-1) return 1ll;
        if(paths[i][j] != -1) return paths[i][j];
        ll p = (self(i+1, j, self) + self(i, j+1, self)) % MOD ;
        return paths[i][j] = p;
    };
    cout << dfs(0, 0, dfs) << nl;
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