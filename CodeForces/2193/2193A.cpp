/*
 * Author: vss_1307
 * Created: 2026-01-25 20:32:54
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, k, y; cin >> n >> k >> y;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll s = accumulate(v.begin(), v.end(), 0ll);
    if(k >= s && (k - s) % y == 0) cout << "YES" << nl;
    else cout << "NO" << nl;
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