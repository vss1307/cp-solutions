/*
 * Author: vss_1307
 * Created: 2026-03-16 20:34:05
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
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector <ll> col(n, -1);
    bool check = true;
    array<ll, 2> a = {0, 0};
    auto dfs = [&](ll i, ll p, auto &self)->void{
        a[col[i]]++;
        for(auto &child : v[i]){
            if(col[child] == col[i]) check = false; 
            if(child != p && col[child] == -1){
                col[child] = (col[i]^1);
                self(child, i, self);
            }
        }
    };
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(col[i] != -1) continue;
        col[i] = 0;
        dfs(i, -1, dfs);
        if(check) ans += max(a[0], a[1]);
        a[0] = 0;
        a[1] = 0;
        check = true;
    }
    cout << ans << nl;
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