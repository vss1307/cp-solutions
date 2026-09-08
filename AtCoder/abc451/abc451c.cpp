/*
 * Author: vss_1307
 * Created: 2026-03-29 09:34:36
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int q; cin >> q;
    multiset <ll> s;
    while(q--){
        ll t, h; cin >> t >> h;
        switch (t)
        {
        case 1:
            s.insert(h);
            break;
        case 2:
            while(s.size() && *s.begin() <= h) s.erase(s.begin());
            break;
        default:
            break;
        }
        cout << s.size() << nl;
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