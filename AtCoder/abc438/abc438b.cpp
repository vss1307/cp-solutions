/*
 * Author: vss_1307
 * Created: 2025-12-27 17:36:56
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
    string s,t; cin >> s >> t;
    ll ans = INT_MAX;
    for(int i = 0; i <= n - m; i++){
        string sub = s.substr(i, m);
        cout <
        ll op = 0;
        for(int j = 0; j < m; j++){
            op += (sub[i] - t[i] + 10) % 10;
        }
        ans = min(ans, op);
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