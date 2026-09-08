/*
 * Author: vss_1307
 * Created: 2026-04-18 17:34:11
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
    vector <vector <ll> > v(n);
    for(int i = 0 ; i < m; i++){
        ll x, y; cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
    }
    vector <bool> vis(n);
    vis[0] = true;
    ll ans = 1;
    auto dfs = [&](ll i, auto &self)->void{
        for(auto &child : v[i]){
            if(!vis[child]){
                vis[child] = true;
                ans++;
                self(child, self);
            }
        }
    };
    dfs(0, dfs);
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