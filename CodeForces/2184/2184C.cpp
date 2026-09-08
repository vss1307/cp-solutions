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
    ll x, k; cin >> x >> k;
    if(k > x){
        cout << -1 << nl; return;
    }
    if(k == x){
        cout << 0 << nl; return;
    }
    ll x1 = x, x2 = x;
    ll ans = 0;
    while(x2 > k){
        ans++;
        x1 = (x1) / 2;
        x2 = (x2 + 1) / 2;
        if(x1 <= k && k <= x2){
            cout << ans << nl; return;
        }
    }
    cout << -1 << nl;
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