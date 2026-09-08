/*
 * Author: vss_1307
 * Created: 2025-12-27 20:09:43
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
    ll n = s.size();
    ll ans = 0;
    if(s[0] == 'u') ans++, s[0] = 's';
    if(s[n-1] == 'u') ans++, s[n-1] = 's';
    for(int i = 1; i < n-1; i++){
        if(s[i] == 'u' && s[i-1] == 'u') s[i] = 's', ans++;
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