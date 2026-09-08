/*
 * Author: vss_1307
 * Created: 2025-12-27 14:26:11
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll       mmmn;
vector <string> v;

string func(ll i, ll j){
    if(i >= n || j >= n) return "a";
    string s = "";
    s += v[i][j];
    return s + min(func(i+1, j), func(i, j+1));
}


void solve(){ 
    cin >> n;
    v.resize(n);
    for(auto &x : v) cin >> x;
    cout << func(0, 0).substr(0, 2*n-1) << nl;
    // vector <vector <ll> > dp(n, vector <ll> (n, 27));
    // dp[n][n] = v[n-1][n-1];
    // for(int i = n; i > -1; i--){
    //     for(int j = n; j > -1; j--){
    //            if(i+1 <= n) dp[i][j] = min(dp[i][j], dp[i+1][j])
    //     }
    // } 
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