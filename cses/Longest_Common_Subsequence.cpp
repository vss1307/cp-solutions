/*
 * Author: vss_1307
 * Created: 2025-12-27 01:01:21
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
    vector <ll> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector <vector <ll> > dp(n+1, vector <ll> (m+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    // for(auto &x : dp){
    //     for(auto &y : x) cout << y << ' '; cout << nl;
    // }
    ll curr = n;
    vector <ll> ans;
    ll i = n, j = m;
    while(i > 0 && j > 0 && ans.size() < dp[n][m]){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--, j--;
        }
        else if(dp[i-1][j] < dp[i][j-1]) j--;
        else i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x << ' '; cout << nl;
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