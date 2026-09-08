/*
 * Author: vss_1307
 * Created: 2026-01-14 20:00:58
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
    vector <int> v(26);
    for(auto &x : s) v[x-'a']++;
    if(*max_element(v.begin(), v.end()) > 2) cout << "NO" << nl;
    else cout << "YES" << nl;
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