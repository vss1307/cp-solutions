/*
 * Author: vss_1307
 * Created: 2025-12-19 20:12:44
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
    vector <string> v(n);
    for(auto &x : v) cin >> x;
    string ans = "";
    for(int i = 0; i < n; i++){
        string a = ans + v[i];
        string b = v[i] + ans;
        ans = min(a, b);
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