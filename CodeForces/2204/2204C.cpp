/*
 * Author: vss_1307
 * Created: 2026-03-16 20:18:36
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll a, b, c, m; cin >> a >> b >> c >> m;
    ll lab = a * b / __gcd(a,b);
    ll lac = a * c / __gcd(a,c);
    ll lbc = b * c / __gcd(c,b);
    ll labc = lab * c / __gcd(lab, c);
    // cout << lab << ' ' << lac << ' ' << lbc << ' ' << labc << nl;
    array <ll, 3> ans = {6 * (m/a) - 3 * (m/lab) - 3 * (m/lac) + 2 * (m/labc), 
        6 * (m/b) - 3 * (m/lab) - 3 * (m/lbc) + 2 * (m/labc), 
        6 * (m/c) - 3 * (m/lbc) - 3 * (m/lac) + 2 * (m/labc)};
    for(auto &x : ans) cout << x << ' '; cout << nl;
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