/*
 * Author: vss_1307
 * Created: 2026-03-14 17:38:40
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, l, r; cin >> n >> l >> r;
    vector < vector <int> > v(n+1, vector <int>(26));
    string s ; cin >> s;
    for(int i = 0; i < n; i++){
        v[i+1][s[i]-'a']++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            v[i+1][j] += v[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int u = min(n, i + r + 1);
        int lb = i + l;
        if(u == lb) break;
        ans += v[u][s[i]-'a'] - v[lb][s[i]-'a'];
    }
    cout << ans << nl;
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