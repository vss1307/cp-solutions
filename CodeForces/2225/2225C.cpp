/*
 * Author: vss_1307
 * Created: 2026-04-21 20:16:42
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    string s,t; cin >> s >> t;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == t[i]) continue;
        if(i+1 < n){
            if(s[i] == s[i+1] && t[i] == t[i+1]){
                i++; continue;
            }
        }
        ans++;
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