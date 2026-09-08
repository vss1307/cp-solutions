/*
 * Author: vss_1307
 * Created: 2026-04-13 20:39:03
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll s, l; cin >> s >> l;
    ll t = s + l*2;
    for(ll n = 1; n <= t; n++){
        if((t-n) % (2*n+1) != 0 ) continue;
        ll m = (t-n) / (2*n+1);
        if(m < n) break;
        bool cond = false;
        ll x = m - n;
        ll t1 = 2 * x * n + x;
        if(s >= x && t1 + 2 * n * (n+1) == t) cond = true;
        if(cond){
            // cout << x << ' ' << t1 << nl;
            cout << n << ' ' << m << nl;
            return;
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