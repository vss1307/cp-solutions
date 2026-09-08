/*
 * Author: vss_1307
 * Created: 2026-01-25 20:56:14
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
    vector <ll> dp(n+1, INT_MAX);
    for(auto &x : v) dp[x] = 1;
    for(ll i = 1; i <= n; i++){
        if(dp[i] == INT_MAX) continue;
        for(ll j = 2 * i; j <= n; j+=i){
            if(dp[j/i] == INT_MAX) continue;
            dp[j] = min(dp[j], dp[j/i] + dp[i]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == INT_MAX) cout << -1 << ' ';
        else cout << dp[i] << ' ';
    }
    cout << nl;
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