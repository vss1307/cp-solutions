/*
 * Author: vss_1307
 * Created: 2026-01-07 20:49:41
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m, k; cin >> n >> m >> k;
    if(m >= 2 * max(k-1, n-k) + min(k-1, n-k) - 1){
        cout << n << nl; return;
    }
    ll mx = max(k-1, n-k);
    ll l = 1, r = n;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll x = mid/2;
        ll y = mid - x - 1;
        if(x < y) swap(x,y);
        if(m >= 2 * x + y - 1) l = mid;
        else r = mid; 
    }
    cout << l << nl;
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