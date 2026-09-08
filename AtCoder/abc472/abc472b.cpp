/*
 * Author: vss_1307
 * Created: 2026-08-22 17:32:08
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    int s = accumulate(v.begin(), v.end(), 0);
    int ans = 1e9;
    int curr = 0;
    for(auto &x : v){
        curr += x;
        ans = min(ans, abs(curr - (s - curr)));
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