/*
 * Author: vss_1307
 * Created: 2026-05-16 17:48:23
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll x, y, z; cin >> x >> y >> z;
    ll n = x + y + z;
    vector <vector <ll> > dp(n+1, vector <ll> (3));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for(int i = 0; i < n; i++){
        
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