/*
 * Author: vss_1307
 * Created: 2026-05-06 11:35:32
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
    ll ans = 0;
    for(int i = n-2; i >= 0; i--){
        if(v[i] + v[i+1] > v[i]) v[i] += v[i+1];
        if(v[i] > 0) ans++;
    }
    cout << ans + (v[n-1] > 0) << nl;
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