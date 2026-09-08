/*
 * Author: vss_1307
 * Created: 2026-02-08 16:13:04
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n , m; cin >> n >> m;
    vector < vector <ll> > v(n, vector <ll>(m));
    for(auto &x : v){
        for(auto &y : x) cin >> y;
    }
    auto dfs = [&](ll i, ll j, array<ll, 4> a, auto &self)->array<ll, 4>{
        // cout << i << ' ' << j << ' ' << a[0] << ' ' << a[1] << nl;
        if(i == n || j == m){
            if((i == n && j == m-1) || (i == n-1 && j == m)) return a;
            a[0] = LLONG_MIN;
            return a;
        }
        a[0] += v[i][j];
        if(v[i][j] > a[1]) a[1] = v[i][j], a[2] = i, a[3] = j;
        auto x = self(i+1, j, a, self);
        auto y = self(i, j+1, a, self);
        if(x[0] < y[0]) return y;
        return x;
    };
    array<ll, 4> x;
    x[0] = 0, x[1] = INT_MIN, x[2] = -1, x[3] = -1;
    x = dfs(0, 0, x, dfs);
    if(v[x[2]][x[3]] >= 0) v[x[2]][x[3]] *= -1;
    x[0] = 0, x[1] = INT_MIN, x[2] = -1, x[3] = -1;
    x = dfs(0, 0, x, dfs);
    cout << x[0] << nl;
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