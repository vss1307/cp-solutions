/*
 * Author: vss_1307
 * Created: 2025-12-19 20:05:37
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int l, a, b; cin >> l >> a >> b;
        int ans = a;
        for(int i = 0; i < l; i++){
            a = (a + b) % l;
            ans = max(ans,a);
        }
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