/*
 * Author: vss_1307
 * Created: 2026-05-23 20:12:10
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
    vector <ll> a(n), b(n);
    for(auto &x :a) cin >> x;
    for(auto &x : b) cin >> x;
    ll ans = 0;
    ll x = 0;
    for(int i = 0; i < n; i++){
        ans += max(a[i], b[i]);
        x = max(x, min(a[i], b[i]));
    }
    cout << ans + x << nl;
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