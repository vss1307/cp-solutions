/*
 * Author: vss_1307
 * Created: 2026-02-08 14:45:37
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, x, y; cin >> n >> x >> y;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    vector <ll> s(n);
    ll t = 0;
    for(int i = 0; i < n; i++){
        s[i] = v[i]/x * y;
        t += s[i];
    }
    ll mx = 0;
    for(int i = 0; i < n; i++){
        mx = max(mx, t - s[i] + v[i]);
    }
    cout << mx << nl;
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