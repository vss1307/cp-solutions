/*
 * Author: vss_1307
 * Created: 2025-12-24 20:03:26
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
    vector <ll> v(n), c(n);
    for(auto &x : v) cin >> x;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        if(i > 0) c[i] = min(c[i], c[i-1]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += v[i] * c[i];
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