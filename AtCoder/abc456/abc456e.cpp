/*
 * Author: vss_1307
 * Created: 2026-05-02 18:19:05
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
    vector <vector <ll> > graph(n);
    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll w; cin >> w;
    vector <string> v(n);
    for(auto &x : v) cin >> x;
    vector <vector <ll> > dp(w+1, vector <ll> (n));
    for(int i = 0; i < n; i++){
        if(v[i][0] == 'o') dp[w][i] = 1;
    }
    for(int i = w-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(v[j][i] == 'x') continue;
            for(int k = 0; k < graph[j].size(); k++) dp[i][j] |= dp[i+1][graph[j][k]];
            dp[i][j] |= dp[i+1][j];
        }
    }
    // for(auto &x : dp){
    //     for(auto &y : x) cout << y << ' '; cout << nl;
    // }
    for(int i = 0; i < n; i++){
        if(dp[0][i] && dp[w][i]){cout << "Yes" << nl; return;}
    }
    cout << "No" << nl;
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