/*
 * Author: vss_1307
 * Created: 2025-12-25 22:09:01
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, x; cin >> n >> x;
    vector <array<ll, 2> > c(n);
    for(auto &a : c) cin >> a[0];
    for(auto &a : c) cin >> a[1];
    sort(c.begin(), c.end());
    ll dp[x+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = x; j > -1; j--){
            if(dp[j] != -1 && j + c[i][0] <= x) dp[j + c[i][0]] = max(dp[j + c[i][0]], dp[j] + c[i][1]);
        }
    }
    cout << *max_element(dp, dp+x+1) << nl;
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