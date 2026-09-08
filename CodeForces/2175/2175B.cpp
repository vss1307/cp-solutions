/*
 * Author: vss_1307
 * Created: 2025-12-06 14:08:33
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, l, r; cin >> n >> l >> r;
    // l--, r--;
    vector <ll> ans(n+1);
    for(int i = 0; i <= n; i++) ans[i] = i;
    ans[r] = l-1;
    for(int i = 1; i <= n; i++){
        cout << (ans[i]^ans[i-1]) << ' ';
    }
    cout << nl;
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