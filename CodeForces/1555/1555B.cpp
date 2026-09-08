/*
 * Author: vss_1307
 * Created: 2026-08-27 19:33:38
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int h, w; cin >> w >> h;
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    int x, y; cin >> x >> y;
    auto func = [&](int u, int v) -> int{
        int u1 = u + x, v1 = v + y;
        // cout << u << ' ' << v << ' ' << u1 << ' ' << v1 << nl;
        if(a.first >= u1 || b.first <= u || a.second >= v1 || b.second <= v) return 0;
        int ans = 1e9;
        if((a.first >= u && a.first <= u1) || (u <= b.first && u1 >= b.first)){
            // either u1 becomes <= a.first
            if(u1 - a.first + b.first >= 0 && u1 - a.first + b.first <= w) ans = min(ans, abs(u1 - a.first));
            // cout << ans << nl;
            // u becomes greater than or equal to b.first
            if(u - b.first + a.first >= 0 && u - b.first + a.first <= w) ans = min(ans, abs(u - b.first));
            // cout << ans << nl;
        }
        if((a.second >= v && a.second <= v1) || (v <= b.second && v1 >= b.second)){
            // either v1 becomes <= a.second
            if(v1 - a.second + b.second >= 0 && v1 - a.second + b.second <= h) ans = min(ans, abs(v1 - a.second));
            // cout << ans << nl;
            // v becomes greater than or equal to b.second
            if(v - b.second + a.second >= 0 && v - b.second + a.second <= h) ans = min(ans, abs(v - b.second));
            // cout << ans << nl;
        }
        return ans;
    };
    int ans = 1e9;
    ans = min(ans, func(0, 0));
    ans = min(ans, func(0, h - y));
    ans = min(ans, func(w-x, 0));
    ans = min(ans, func(w-x, h-y));
    cout << (ans == 1e9? -1 : ans) << nl;
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