/*
 * Author: vss_1307
 * Created: 2026-01-28 20:27:23
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector < vector <ll > > dp(m+1, vector <ll> (2, INT_MAX));
    ll ans = INT_MAX;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        vector < vector <ll > > ndp(m+1, vector <ll> (2, INT_MAX));
        ndp[0][0] = ndp[0][1] = 1;
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]) ndp[j][0] = min({ndp[j][0], dp[j-1][0], dp[j-1][1]});
            ndp[j][1] = min({ndp[j][1], dp[j][0]+1, dp[j][1]});
        }
        dp = ndp;
    }
    ans = min(ans, min(dp[m][1], dp[m][0]));
    if(ans == INT_MAX) cout << -1 << nl;
    else cout << ans << nl;
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