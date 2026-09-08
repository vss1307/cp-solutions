/*
 * Author: vss_1307
 * Created: 2026-04-26 10:07:52
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k, p, q; cin >> n >> k >> p >> q;
    vector <ll> a(n);
    for(auto &x : a) cin >> x;
    vector <ll> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + min(a[i] % p, (a[i] % q) % p);
    ll currp = 0;
    ll currq = 0;
    for(int i = 0; i < k; i++){
        currp += a[i] % p;
        currq += (a[i] % q) % p;
    }
    ll ans = min(currp + pref[n] - pref[k], currq + pref[n] - pref[k]);
    // cout << ans << ' ' << currp << ' ' << currq << ' ' << pref[n] - pref[k] << nl;
    for(int i = k; i < n; i++){
        currp += a[i] % p;
        currp -= a[i-k] % p;
        currq += (a[i] % q) % p;
        currq -= (a[i-k] % q) % p;
        ans = min({ans, currp + pref[n] - pref[i+1] + pref[i-k+1], currq + pref[n] - pref[i+1] + pref[i-k+1]});
        // cout << ans << ' ' << currp << ' ' << currq << ' ' << pref[n] - pref[i+1] << nl;
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