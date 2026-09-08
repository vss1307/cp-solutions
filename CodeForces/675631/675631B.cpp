/*
 * Author: vss_1307
 * Created: 2026-03-01 14:44:37
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll s; cin >> s;
    ll l = 0, r = 62;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll func = (1ll << (mid+1)) - 1;
        if(func < s) l = mid;
        else r = mid; 
    }
    cout << r << nl;
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