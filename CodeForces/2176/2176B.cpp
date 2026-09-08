/*
 * Author: vss_1307
 * Created: 2025-12-11 20:06:06
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n ; cin >> n;
    string s; cin >> s;
    s += s;
    int i = 0;
    for(i = 0; i < n; i++){
        if(s[i] == '1') break;
    }
    ll ans = 0;
    ll last = 0;
    for(int j = 0; j < n; j++){
        if(s[i+j] == '1') last = j;
        else{
            ans = max(ans, j - last);
        }
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