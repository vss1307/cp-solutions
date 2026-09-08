/*
 * Author: vss_1307
 * Created: 2026-01-14 20:47:33
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector <vector <ll> > v(n);
    map <ll, pair <ll, ll> > mp;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> v[i][j];
            mp[v[i][j]] = {i, j};
        }
    }
    ll ans = n * m + 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            auto [k,l] = mp[j+1 + m * (i)];
            ll x = (abs(i - k) + 1) * (abs(j - l) + 1);
            if(x) ans = min(ans, )
        }
    }
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