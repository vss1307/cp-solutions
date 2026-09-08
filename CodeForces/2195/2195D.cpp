/*
 * Author: vss_1307
 * Created: 2026-02-15 20:46:19
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector <ll> ans(n);
    ll s = (v[0] + v.back()) / (n-1);
    ll cur = 0;
    for(int i = 0; i < n-1; i++){
        ll a = (v[i+1] - v[i] + s)/2;
        ans[i] = a - cur;
        cur += ans[i];
    }
    ans.back() = s - cur;
    for(auto &x : ans) cout << x << ' '; cout << nl;
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