/*
 * Author: vss_1307
 * Created: 2026-04-25 20:17:04
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
    vector <vector <ll> > v(2);
    vector <bool> pos(2);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v[i%2].push_back(x);
        if(x >= 0) pos[i%2] = true;
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ll j; cin >> j;
        j--;
        j%=2;
        if(v[j%2].size()){
            if(v[j].back() >= 0 || pos[j] == false){
                pos[j] = true;
                v[j%2].pop_back();
            }
        }
    }
    for(auto &x : v){
        for(auto &y : x) ans += y;
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