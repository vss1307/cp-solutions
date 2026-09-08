/*
 * Author: vss_1307
 * Created: 2026-08-12 10:38:06
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    ll ans = LLONG_MAX;
    for(int mask = 0; mask < (1<<n); mask++){
        ll s = 0;
        for(int i = 0; i < n; i++){
            if((mask)&(1<<i)) s += v[i];
        }
        ans = min(ans, abs(sum - 2 * s));
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