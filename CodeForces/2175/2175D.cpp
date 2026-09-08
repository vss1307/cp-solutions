/*
 * Author: vss_1307
 * Created: 2025-12-06 15:00:42
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
    vector <ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <vector <pair <ll, ll>>> dp(n+1, vector <pair <ll, ll>>(k+1, {-1, -1}));
    dp[0][0] = {0, 0};
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= k; j++){
            if(dp[i][j].first == -1) continue;
            for(ll l = 0; j + l <= k && l <= a[i]; l++){
                ll mx = max(dp[i][j].second, l);
                ll tot = dp[i][j].first + (n-i)*mx;
                if(dp[i+1][j+l].first + (n-i-1)*dp[i+1][j+l].second < tot){
                    dp[i+1][j+l] = {dp[i][j].first + mx, mx};
                }
            }
        }
    }
    ll ans = 0;
    for(auto &x : dp[n]) ans = max(ans, x.first);
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
