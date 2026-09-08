/*
 * Author: vss_1307
 * Created: 2025-12-06 02:47:09
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
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    ll mx = 0, mn = 0;
    for (int i = 1; i <= n; ++i) {
        ll new_mx = max(mx - a[i], b[i] - mn);
        ll new_mn = min(mn - a[i], b[i] - mx);
        mx = new_mx, mn = new_mn;
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
    // #endif
    int te; cin >> te;
    while (te--)
        solve();
}