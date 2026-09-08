/*
 * Author: vss_1307
 * Created: 2026-05-16 17:30:33
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string s; cin >> s;
    ll sz = s.size();
    ll n; cin >> n;
    for(int i = 0; i < sz; i++){
        if(!(abs(i) < n || abs(sz - i) < n+1)) cout << s[i];
        // else cout << i << nl;
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