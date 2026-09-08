/*
 * Author: vss_1307
 * Created: 2026-08-17 16:46:05
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
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    vector<ll> pref(n+1), suff(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + v[i];
    for(int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + v[i];
    sort(suff.begin(), suff.end());
    // for(auto &x : suff) cout << x << ' '; cout << nl;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll l = i+1;
        ll r = lower_bound(suff.begin(), suff.end(), pref[l]) - suff.begin();
        // cout << l << ' ' << r << nl;
        if(l + r <= n && pref[l] == suff[r]) ans = max(ans, pref[l]);
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