/*
 * Author: vss_1307
 * Created: 2026-02-04 20:01:03
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll b , g, x, y , n; cin >> b >> g >> x >> y >> n;
    if(n - x - y < 0){
        cout << -1 << nl; return;
    }
    ll l = 0, r = 1e9 + 1;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll remb = b - mid * x;
        ll remg = g - mid * y;
        if(remb < 0 || remg < 0 || remb + remg <= mid * (n - x - y)) r = mid;
        else l = mid;
    }
    ll remb = b - r * x;
    ll remg = g - r * y;
    if(remb >= 0 && remg >= 0 && remb + remg <= r * (n - x - y)) cout << r << nl;
    else cout << -1 << nl;
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