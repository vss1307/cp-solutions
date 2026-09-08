/*
 * Author: vss_1307
 * Created: 2026-01-02 19:01:46
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll a, b; cin >> a >> b;
    int ans = 0;
    for(int rot = 0; rot < 2; rot++){
        ll ta = 0, tb = 0;
        int layer = 0;
        for(int i = 0; i < 30; i++){
            if((i&1) && ta + (1ll<<i) <= a) ta += (1ll<<i), layer++;
            else if(!(i&1) && tb + (1ll<<i) <= b) tb += (1ll<<i), layer++;
            else break;
        }
        ans = max(ans, layer);
        swap(a,b);
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