/*
 * Author: vss_1307
 * Created: 2026-02-11 20:32:59
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
    if(a >= b) cout << "Alice" << nl;
    else{
        ll d = b - a;
        if(a >= 2 * d && b >= 3 * d) cout << "Bob" << nl;
        else cout << "Alice" << nl;
    }
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