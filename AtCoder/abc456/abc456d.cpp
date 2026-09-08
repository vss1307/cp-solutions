/*
 * Author: vss_1307
 * Created: 2026-05-02 17:47:55
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string s; cin >> s;
    int n = s.size();
    vector <ll > dp(4, 0);
    dp[0] = 1;
    map <char, ll> mp;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    for(int i = 0; i < n;){
        vector <ll> ndp(4,0);
        ndp[mp[s[i]]] = dp[mp[s[i]]];
        int j = i;
        while(j < n && s[j] == s[i]) j++;
        for(int k = 0; k < 4; k++){
            if(k != mp[s[i]]){
                ndp[k] = dp[k] % MOD;
                ndp[mp[s[i]]] += (j-i) * (dp[k]) % MOD;
            }
        }
        dp = ndp;
        i = j;
    }
    ll ans = 0;
    for(auto &x : dp) ans = (ans + x) % MOD;
    cout << (ans - 1 + MOD) % MOD << nl;
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