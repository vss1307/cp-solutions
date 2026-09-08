/*
 * Author: vss_1307
 * Created: 2026-01-26 21:45:29
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    map <ll, pair <ll, ll> > mp;
    vector < ll > vx(n);
    for(auto &x : vx) cin >> x;
    for(auto &x : vx){
        ll y; cin >> y;
        if(mp.count(x) == 0) mp[x] = {y, y};
        mp[x].first = min(mp[x].first, y);
        mp[x].second = max(mp[x].second, y);
    }
    vector <array<ll, 3>> v;
    v.reserve(mp.size());
    for(auto &[x, y] : mp) v.push_back({x, y.first, y.second});
    map <ll, map <ll, ll>> dp;
    auto func = [&](ll x, ll y, ll i, auto &self) -> ll{
        if(i == v.size()) return abs(bx - x) + abs(by - y);
        if(dp.count(x) && dp[x].count(y)) return dp[x][y];
        ll r1 = abs(x - v[i][0]) + abs(y - v[i][1]) + v[i][2] - v[i][1];
        ll r2 = abs(x - v[i][0]) + abs(y - v[i][2]) + v[i][2] - v[i][1];
        return dp[x][y] = min(r1 + self(v[i][0], v[i][2], i+1, self), r2 + self(v[i][0], v[i][1], i+1, self));
    };
    cout << func(ax, ay, 0ll, func) << nl;
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