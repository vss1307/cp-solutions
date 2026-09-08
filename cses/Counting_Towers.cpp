/*
 * Author: vss_1307
 * Created: 2025-12-25 23:40:35
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
    vector <array<ll, 6> > dp(n);
    dp[0][0] = dp[0][1] = 1;
    for(ll i = 1; i <= n; i++){
        // dp[i][0] is the sum of all previous
        for(ll j = 0; j < 6; j++) dp[i][0] = (dp[i][0] + dp[i-1][j]) % MOD;
        // dp[i][1] is the sum of dp[i-1][0, 1, 2, 3]
        for(ll j = 0; j < 4; j++) dp[i][1] = (dp[i][1] + dp[i-1][j]) % MOD;
        // dp[i][2] is the sum of dp[i-1][0, 1, 2, 3]
        for(ll j = 0; j < 4; j++) dp[i][2] = (dp[i][2] + dp[i-1][j]) % MOD;
        // dp[i][3] is the sum of dp[i-1][0, 1, 2, 3]
        for(ll j = 0; j < 4; j++) dp[i][3] = (dp[i][3] + dp[i-1][j]) % MOD;
        // dp[i][4] is the sum of all previous
        for(ll j = 0; j < 6; j++) dp[i][4] = (dp[i][4] + dp[i-1][j]) % MOD;
        // dp[i][5] is the sum of dp[i-1][4, 5]
        for(ll j = 4; j < 6; j++) dp[i][5] = (dp[i][5] + dp[i-1][j]) % MOD;
    }
    ll ans = 0;
    for(ll j = 0; j < 6; j++) ans = (ans + dp[n][j]) % MOD;
    cout << ans << nl;
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