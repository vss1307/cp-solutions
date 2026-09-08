/*
 * Author: vss_1307
 * Created: 2025-12-25 21:48:04
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> dig(ll n){
    vector <ll> digits;
    while(n){
        digits.push_back(n%10);
        n/=10;
    }
    return digits;
}

void solve(){ 
    ll n; cin >> n;
    vector <ll> dp(n+1, LLONG_MAX/2);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        vector <ll> digits = dig(i);
        for(auto &d : digits) dp[i] = min(dp[i], dp[i-d] + 1);
    }
    cout << dp[n] << nl;
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