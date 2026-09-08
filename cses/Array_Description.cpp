/*
 * Author: vss_1307
 * Created: 2025-12-25 22:32:10
 */
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve(){ 
    ll n, m; cin >> n >> m;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++) dp[i][0] = -1;
    for(int i = 0; i < n; i++){
        if(v[i] == 0) continue;
        for(int j = 1; j <= m; j++) dp[i][j] = -1;
        dp[i][v[i]] = 0;
    }
    for(int i = 0; i <= m; i++) if(dp[0][i] != -1) dp[0][i] = 1;
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == -1) continue;
            if(dp[i+1][j] != -1) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            if(j + 1 <= m && dp[i+1][j+1] != -1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            if(j - 1 > 0 && dp[i+1][j-1] != -1) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
        }
    }
    ll ans = 0;
    for(auto &x : dp[n-1]) if(x != -1) ans = (ans + x) % MOD;
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