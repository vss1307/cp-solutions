/*
 * Author: vss_1307
 * Created: 2025-12-07 16:11:39
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    vector <ll> v(n);
    for(auto &x: v) cin >> x;
    sort(v.begin(), v.end());
    vector <ll> next_val(n);
    int next = 0;
    for(int i = 0; i < n; i++){
        while(next < n && v[next] - v[i] <= 5) next++;
        next_val[i] = next;
    }
    vector <vector <ll> > dp(n+1, vector <ll> (k+1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == -1) continue;
            if(j+1 <= k) dp[next_val[i]][j+1] = max(dp[next_val[i]][j+1], dp[i][j] + next_val[i] - i);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    } 
    ll ans = 0;
    for(int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
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