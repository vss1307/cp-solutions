/*
 * Author: vss_1307
 * Created: 2025-12-24 20:51:29
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
    // cout << __builtin_ctzll(n) << ' ';
    if(n&1){
        if(n == 1) cout << 0 << nl;
        else if(n == 3) cout << 1 << nl;
        else cout << -1 << nl;
        return;
    }
    if(n == 2) cout << 1 << nl;
    else if(n == 6) cout << 2 << nl;
    else if(n%4 == 0){
        ll op = 0;
        while((n&1) == 0){
            op++;
            ll x = __builtin_ctzll(n);
            ll k = (n >> x) ^ 3;
            if(__builtin_popcountll(n) == 1 || k == 0) n/=2;
            else n = (n^3) + 1;
        }
        if(n == 3) op++;
        cout << op << nl;
    }
    else cout << -1 << nl;
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