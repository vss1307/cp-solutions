/*
 * Author: vss_1307
 * Created: 2026-06-06 18:01:25
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, q; cin >> n >> q;
    ll ans = 0;
    set <ll> r, c;
    while(q--){
        ll t, x; cin >> t >> x;
        switch (t)
        {
        case 1:
            if(r.find(x) == r.end()){
                ans += n;
                r.insert(x);
                
            }
            r.insert(x);
            ans += n - c.size();
            break;
        case 2:
            c.insert(x);
            ans -= r.size();
            break;
        }
        cout << ans << nl;
    }
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