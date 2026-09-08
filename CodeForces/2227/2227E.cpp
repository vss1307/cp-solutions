/*
 * Author: vss_1307
 * Created: 2026-05-03 17:44:42
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
    vector <ll> v(n), h(n);
    for(auto &x : v){
        cin >> x;
    }
    vector <ll> v1(n);
    ll l = n;
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(l < v[i]) v1[i] = l;
        else v1[i] = v[i];
        l = min(l, v[i]);
        ans += v[i] - v1[i];
        h[v1[i]-1]++;
        // cout << v1[i] << ' ';
    }
    for(int i = n-2; i >= 0; i--) h[i] += h[i+1];
    // for(auto &x : h) cout << x << ' '; cout << nl;
    // for(auto &x : v1) cout << x << ' '; cout << nl;
    pair <ll, ll> s = {0, 0};
    for(ll i = n-1; i >= 0; i--) if(h[v1[i] - 1] - (n-i) > s.first) s = {h[v1[i] - 1] - (n-i), i};
    cout << ans + s.first << nl;
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