/*
 * Author: vss_1307
 * Created: 2026-01-25 20:49:29
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
    vector <ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    vector <ll> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + b[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll j = upper_bound(pref.begin(), pref.end(), n-i) - pref.begin();
        j--;
        ans = max(ans, j * a[i]);
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