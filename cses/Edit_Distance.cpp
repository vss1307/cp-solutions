/*
 * Author: vss_1307
 * Created: 2025-12-26 22:57:23
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string s,t; cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    vector <vector <ll> > dp(n+1, vector <ll>(m+1, INT_MAX));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(i>0 && j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + !(s[i-1] == t[j-1]));
        }
    }
    // for(auto &x : dp){
    //     for(auto &y : x) cout << y << ' '; cout << nl;
    // }
    cout << dp[n][m] << nl;
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