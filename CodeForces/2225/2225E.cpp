/*
 * Author: vss_1307
 * Created: 2026-04-21 21:16:17
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, r; cin >> n >> r;
    vector <pair <ll, ll>> v(n);
    pair <ll, ll> mn = {INT_MAX, INT_MAX};
    for(auto &[x,y]: v) cin >> x >> y;
    sort(v.begin(), v.end());
    
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