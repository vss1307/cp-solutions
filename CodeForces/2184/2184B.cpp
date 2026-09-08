/*
 * Author: vss_1307
 * Created: 2026-01-16 14:53:35
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k, m; cin >> n >> k >> m;
    if(k >= n){
        cout << max(0ll, n - (m%k)) << nl;
        return;
    }
    ll x = m/k;
    m %= k;
    if(x&1){
        cout << k - m << nl; return;
    }
    else{
        cout << n - m << nl; return;
    }
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