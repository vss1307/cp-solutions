/*
 * Author: vss_1307
 * Created: 2026-08-17 17:10:48
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> v;
vector<int> seq;
vector<pair<int, int>> w;

void dfs(int curr){
    seq.push_back(curr);
    w[curr].first = seq.size() - 1;
    for(auto &x : v[curr]){
        if(w[x].first == -1) dfs(x);
    }
    w[curr].second = seq.size() - 1;
}

void solve(){ 
    int n, q; cin >> n >> q;
    v.resize(n);
    w.resize(n, {-1, -1});
    for(int i = 0; i < n-1; i++){
        int x ; cin >> x;
        v[x-1].push_back(i+1);
    }
    dfs(0);
    // for(auto &[x,y] : w) cout << x << ' ' << y << nl;
    while(q--){
        int u, k; cin >> u >> k;
        u--;
        // cout << u << ' ' << k << ' ' << w[u].first + k - 1 << nl;
        if(w[u].second - w[u].first + 1 < k) cout << -1 << nl;
        else cout << seq[w[u].first + k - 1] + 1 << nl; 
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