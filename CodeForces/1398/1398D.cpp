/*
 * Author: vss_1307
 * Created: 2026-09-04 14:06:53
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r, g, b;
vector<ll> vr, vg, vb;
vector<vector<vector<ll>>> dp;

ll func(int i, int j, int k){
    // cerr << i << ' ' << j << ' ' << k << nl;
    if(i < 0 || j < 0 || k < 0) return 0ll;
    if(dp[i][j][k]) return dp[i][j][k];
    return dp[i][j][k] = max({vr[i] * vg[j] + func(i-1, j-1, k), vg[j]*vb[k] + func(i, j-1, k-1), vr[i]*vb[k] + func(i-1, j, k-1)});
}

void solve(){ 
    cin >> r >> g >> b;
    dp.resize(r+1, vector<vector<ll>>(g+1, vector<ll>(b+1, 0)));
    vr.resize(r+1);
    vg.resize(g+1);
    vb.resize(b+1);
    for(int i = 0; i < r; i++) cin >> vr[i+1];
    for(int i = 0; i < g; i++) cin >> vg[i+1];
    for(int i = 0; i < b; i++) cin >> vb[i+1];
    sort(vr.begin(), vr.end());
    sort(vg.begin(), vg.end());
    sort(vb.begin(), vb.end());
    cout << func(r, g, b) << nl;
    // for(auto &x : dp){
    //     for(auto &y : x){
    //         for(auto &z : y) cout << z << ' '; cout << nl;
    //     }
    //     cout << nl;
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