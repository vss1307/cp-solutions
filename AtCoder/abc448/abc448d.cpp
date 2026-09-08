/*
 * Author: vss_1307
 * Created: 2026-03-07 17:44:51
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
    vector <vector <ll> > g(n);
    for(int i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <ll> t(n);
    multiset <ll> s;
    auto dfs = [&](ll i, ll p, auto &self)->void{
        s.insert(v[i]);
        for(auto &child : g[i]){
            if(child != p){
                if(s.find(v[child]) != s.end()){
                    t[child] = 1;
                }
                t[child] = max(t[i], t[child]);
                self(child, i, self);
            }
        }
        s.erase(s.find(v[i]));
    };
    dfs(0, -1, dfs);
    for(int i = 0; i < n; i++){
        cout << (t[i] ? "Yes" : "No") << nl;
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