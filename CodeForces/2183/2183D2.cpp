/*
 * Author: vss_1307
 * Created: 2026-01-07 22:02:00
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    vector <vector <ll> > g(n);
    for(int i = 0; i < n-1; i++){
        ll x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector <vector <ll> > d(n);
    d[0] = {1};
    vector <ll> dep(n);
    auto dfs = [&](ll i, ll p, auto &self)->void{
        for(auto &child : g[i]){
            if(child == p) continue;
            dep[child] = dep[i] + 1;
            d[dep[child]].push_back(child);
            self(child, i, self);
        }
    };
    dfs(0, -1, dfs);
    vector <ll> ans(n, 1);
    for(int i = 0; i < n && d[i].size() != 0; i++){
        
    }
    // for(auto &x : d) cout << x << ' '; cout << nl;
    // ll mx = *max_element(d.begin(), d.end());
    // for(int i = 0; i < n; i++){
    //     if(d[dep[i] + 1] == mx && g[i].size() == mx + (i == 0? 0 : 1)){
    //         cout << mx+1 << nl; return;
    //     }
    // }
    // cout << mx << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    int te; cin >> te;
    while (te--)
        solve();
}