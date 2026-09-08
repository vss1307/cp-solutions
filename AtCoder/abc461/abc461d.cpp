/*
 * Author: vss_1307
 * Created: 2026-06-06 17:49:20
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m, k; cin >> n >> m >> k;
    vector <vector <ll> > v(n, vector <ll> (m));
    for(int i = 0 ; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            v[i][j] = s[j] - '0';
        }
    }
    vector <vector <ll> > s(n+1, vector <ll> (m+1));
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            s[i+1][j+1] = v[i][j] + s[i][j+1] + s[i+1][j] - s[i][j];
        }
    }
    ll ans = 0;
    for(int r = 0; r < n; r++){
        for(int r1 = r+1; r1 <= n; r1++){
            vector <ll> v;
            v.push_back(0);
            for(int c = 0; c < m; c++){
                ll total = s[r1][c+1] - s[r][c+1];
                ll f = lower_bound(v.begin(), v.end(), total - k) - v.begin();
                ll l = upper_bound(v.begin(), v.end(), total - k) - v.begin();
                if(v[f] == total - k) ans += l-f;
                v.push_back(total);
            }
        }
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