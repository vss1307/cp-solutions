/*
 * Author: vss_1307
 * Created: 2026-08-22 17:54:43
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, m; cin >> n >> m; 
    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> vis(n);
    int f = -1, l = -1;
    vector<int> ans;
    auto dfs = [&](ll i, auto &self) -> void{
        // cout << i << ':' << nl;
        for(auto &child : v[i]){
            if(vis[child]){
                if(vis[i] == vis[child]){
                    f = i, l = child;
                    // cout << f << ' ' << l << nl;
                }
            }
            else{
                vis[child] = 3 - vis[i];
                self(child, self);
            }
            if(l != -1){
                // cout << i << nl;
                ans.push_back(i);
                if(i == l) l = -1;
                return;
            }
        }
    };
    vis[0] = 1;
    dfs(0, dfs);
    if(ans.empty()){
        cout << -1 << nl; return;
    }
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x+1 << ' '; cout << nl;
    // cout << f << ' ' << l << nl;
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