/*
 * Author: vss_1307
 * Created: 2026-08-17 17:26:59
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> v(n, vector<ll>(m));
    for(auto &x : v) for(auto &y : x) cin >> y;
    ll ans = 0;
    map < pair<ll, ll>, vector<ll> > mp;
    auto dfs = [&](ll i, ll j, ll x, int f, auto &self)->void{
        if(i == n || j == m || j == -1 || i == -1) return;
        x ^= v[i][j];
        if(i + j == (n + m - 1) / 2){
            // cout << i << ' ' << j << ' ' << x << ' ' << f << nl;
            if(f==1) mp[{i,j}].push_back(x);
            else ans += upper_bound(mp[{i, j}].begin(), mp[{i, j}].end(), k^x^v[i][j]) - lower_bound(mp[{i, j}].begin(), mp[{i, j}].end(), k^x^v[i][j]);
            return;
        }
        self(i+f, j, x, f, self);
        self(i, j+f, x, f, self);
    };
    dfs(0, 0, 0, 1, dfs);
    for(auto &[x, y] : mp){
        sort(y.begin(), y.end());
        // for(auto &a : y) cout << a << ' '; cout << nl;
    }
    dfs(n-1, m-1, 0, -1, dfs);
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