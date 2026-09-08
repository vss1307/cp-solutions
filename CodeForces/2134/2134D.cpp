/*
 * Author: vss_1307
 * Created: 2025-12-19 18:33:34
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
    vector <set <int> > v(n);
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        v[x].insert(y);
        v[y].insert(x);
    }
    vector <ll> dep(n, INT_MAX);
    vector <ll> par(n, -1);
    // find the diameter
    dep[0] = 0;
    auto dfs = [&](ll i, auto &self)->void{
        for(auto &child : v[i]){
            if(dep[child] != INT_MAX) continue;
            dep[child] = dep[i] + 1;
            par[child] = i;
            self(child, self);
        }
    };
    dfs(0, dfs);
    // assume that the diameter goes from u to y
    int u = max_element(dep.begin(), dep.end()) - dep.begin();
    dep = vector <ll> (n, INT_MAX);
    dep[u] = 0;
    par[u] = -1;
    dfs(u, dfs);
    int y = max_element(dep.begin(), dep.end()) - dep.begin();
    int i = y;
    set <int> diameter;
    diameter.insert(i);
    // iterate through the vertices of the diameter and find a vertex with deg > 2
    while(par[i] != -1){
        diameter.insert(par[i]);
        if(v[i].size() > 2){
        // choose that vertex as b, choose a child that is on diameter as a, and not on diameter as c
            ll b = i;
            ll a = par[i];
            for(auto child : v[i]){
                if(diameter.find(child) == diameter.end()){
                    cout << a + 1 << ' ' << b + 1 << ' ' << child + 1 << nl;
                    return;
                }
            }
        }
        i = par[i];
    }
    cout << -1 << nl;
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