/*
 * Author: vss_1307
 * Created: 2025-12-24 16:51:11
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
    sort(v.begin(), v.end());
    ll ans = v[0];
    for(ll i = 0; i < n; i++){
        if(v[i] == v[0]) continue;
        if(v[i] > v[0]) ans = max(ans, v[i] - v[0]);
        break;
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