#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll t, h, u; cin >> t >> h >> u;
    ll ans = 0;
    ll x = min(t,u);
    ans += x * 4;
    t -= x, u -= x;
    ans += 3 * u;
    x = min(t/2 * 2, h * 2);
    ans += 7 * (x/2);
    t -= x, h -= x/2;
    if(t == 1 && h){
        ans += 5;
        t--;
        h--;
    }
    if(t) ans += 3 + (t-1) * 2;
    cout << ans + 3 * h << nl;
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