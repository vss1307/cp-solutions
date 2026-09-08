/*
 * Author: vss_1307
 * Created: 2025-12-19 22:13:39
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    if(n == 1){
        cout << 0 << nl; return;
    }
    vector <ll> d(n-1);
    for(int i = 0; i < n-1; i++) d[i] = v[i+1] - v[i];

    vector <array <ll, 3>> dp(n-1);
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = INT_MIN;
    for(int i = 1; i < n-1; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = dp[i-1][0] + 1;
        dp[i][2] = dp[i-1][1] + 1;
        if(i>1 && d[i-1] < d[i-2] + d[i]) dp[i][2] = max(dp[i][2], dp[i-1][2] + 1);
    }
    cout << max({dp[n-2][0], dp[n-2][1], dp[n-2][2]}) << nl;
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