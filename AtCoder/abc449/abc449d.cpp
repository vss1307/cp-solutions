/*
 * Author: vss_1307
 * Created: 2026-03-14 17:52:38
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll l,r,d,u; cin >> l >> r >> d >> u;
    ll ans = 0;

    // vertical points, same x
    ll fx = l;
    if(abs(l) % 2 == 1) fx++;
    for(ll i = fx; i <= r; i+=2){
        ll lb = max(-1 * abs(i) , d);
        ll ub = min(abs(i), u);
        ans += max(0ll, ub - lb + 1);
        // cout << i << ' ' << ub << ' ' << lb << nl;
    }
    // cout << ans << nl;
    // horizontal points, same y
    ll fy = d;
    if(abs(d) % 2 == 1) fy++;
    for(ll i = fy; i <= u; i+=2){
        ll lb = max(-1 * abs(i) + 1, l);
        ll ub = min(abs(i) - 1, r);
        ans += max(0ll, ub - lb + 1);
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