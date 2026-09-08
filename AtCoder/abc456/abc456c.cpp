/*
 * Author: vss_1307
 * Created: 2026-05-02 17:43:01
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
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i >= 1 && s[i] == s[i-1]) j = i;
        ans += i - j + 1;
        ans %= MOD;
        // cout << j << nl;
    }
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