/*
 * Author: vss_1307
 * Created: 2026-01-23 21:26:50
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
    if(__builtin_popcountll(n) == 1){
        cout << -1 << nl; return;
    }
    vector <ll> v(n);
    v[n-1] = 1;
    for(int i = 2; i <= n; i++){
        ll p = (i ^ 1) - 1;
        if(p < n-1) v[p] = i;
        else v[0] = i;
    }
    ll p = __builtin_ctz(n);
    swap(v[0], v[(1ll<<p)-1]);
    for(auto &x : v) cout << x << ' '; cout << nl;
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
