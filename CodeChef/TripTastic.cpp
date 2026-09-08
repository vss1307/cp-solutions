/*
 * Author: vss_1307
 * Created: 2025-12-09 00:55:36
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
    ll tot = 0;
    vector <vector <ll> > v(n, vector <ll>(m));
    for(auto &x : v){
        for(auto &y : x){
            cin >> y;
            tot += y;
        }
    }
    if(tot < k+1){
        cout << -1 << nl; return;
    }
    vector <vector <ll> > pref(n+1, vector <ll> (m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + v[i-1][j-1];
        }
    }
    ll l = -1,r = max(n, m);
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(v[i-1][j-1]) ans = max(ans, pref[min(n, i+mid)][min(m, j+mid)] - pref[min(n, i+mid)][max(0ll, j-mid-1)] - pref[max(0ll, i-mid-1)][min(m, j+mid)] + pref[max(0ll, i-mid-1)][max(0ll, j-mid-1)]);
            }    
        }
        if(ans >= k+1) r = mid;
        else l = mid;
    }
    cout << r << nl;
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