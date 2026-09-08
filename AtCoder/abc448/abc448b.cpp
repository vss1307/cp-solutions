/*
 * Author: vss_1307
 * Created: 2026-03-07 17:32:34
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
    vector <ll> v(m);
    for(auto &x : v) cin >> x;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        a--;
        ll x = min(v[a], b);
        v[a] -= x;
        ans += x;
    }
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