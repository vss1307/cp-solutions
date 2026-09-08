/*
 * Author: vss_1307
 * Created: 2026-01-02 18:59:07
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    string s; cin >> s;
    bool p = false;
    bool a = false;
    for(int i = 0; i < n-3; i++){
        if(s.substr(i, 4) == "2026") p = true;
        if(s.substr(i, 4) == "2025") a = true;
    }
    if(p || !a) cout << 0 << nl;
    else cout << 1 << nl;
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