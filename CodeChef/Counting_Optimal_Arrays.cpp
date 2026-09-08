/*
 * Author: vss_1307
 * Created: 2025-12-24 20:23:44
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
    if(n == 1){
        cout << m+1 << nl; return;
    }
    ll x = 0;
    while( (1ll << x) <= m) x++;
    vector <array<ll, 3>> dp(x+1);
    dp[1][0] = dp[1][2] = 1;
    for(int i = x-2; i >= 0; i--){
        ll bit = (m >> i)&1;
        if(bit){
            dp[x-i][0] = dp[x-i-1][0];
            dp[x-i][1] = 2 * dp[x-i-1][1] + dp[x-i-1][0] + dp[x-i-1][2];
            dp[x-i][2] = dp[x-i-1][2];
        }
        else{
            dp[x-i][0] = dp[x-i-1][0];
            dp[x-i][1] = 2 * dp[x-i-1][1];
            dp[x-i][2] = dp[x-i-1][2];
        }
    }
    cout << dp[x][0] + dp[x][1] + dp[x][2] << nl;
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