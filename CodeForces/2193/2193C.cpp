/*
 * Author: vss_1307
 * Created: 2026-01-25 20:42:32
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, q; cin >> n >> q;
    vector <ll> a(n), b(n), pref(n+1);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    ll la = 0;
    for(int i = n-1; i >= 0; i--){
        a[i] = max({a[i], la, b[i]});
        la = a[i];
    }
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];
    while(q--){
        ll l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << ' ';
    }
    cout << nl;
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