/*
 * Author: vss_1307
 * Created: 2026-08-28 20:56:46
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
    vector<vector<int>> v(n, vector<int>(n));
    for(auto &x : v)
        for(auto &y : x) cin >> y;
    ll ans1 = 0, ans2 = 0;;
    for(int i = 0; i < n; i++){
        ll s1 = 0, s2 = 0;;
        for(int j = 0; j < n; j+=2) s1 += v[i][j];
        for(int j = 1; j < n; j+=2) s2 += v[i][j];
        ans1 += max(s1, s2);
    }
    for(int i = 0; i < n; i++){
        ll s1 = 0, s2 = 0;;
        for(int j = 0; j < n; j+=2) s1 += v[j][i];
        for(int j = 1; j < n; j+=2) s2 += v[j][i];
        ans2 += max(s1, s2);
    }
    cout << max(ans1, ans2) << nl;
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