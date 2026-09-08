/*
 * Author: vss_1307
 * Created: 2025-12-11 20:53:36
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector <vector <pair <ll, ll> > > g(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
    }
    for(int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [&](const auto& a, const auto& b){
            return v[a.first] < v[b.first];
        });
    }
    vector <ll > done(m, -1);
    vector <map <ll, ll> > res(n);
    auto func = [&](ll i, ll parent, ll id, auto &self)->void{
        done[id] = 0;
        ll x = v[i] + v[parent];
        if(res[i].find(x) != res[i].end()){
            done[id] = (done[id] + res[i][x] ) % MOD;
            return;
        }
        ll st = -1, en = -1;
        ll l = -1, r = g[i].size();
        while(r-l > 1){
            ll mid = (r+l) >> 1;
            if(v[g[i][mid].first] < x) l = mid;
            else r = mid;
        }
        st = r;
        l = -1, r = g[i].size();
        while(r-l > 1){
            ll mid = (r+l) >> 1;
            if(v[g[i][mid].first] <= x) l = mid;
            else r = mid;
        }
        en = l;
        for(int j = st; j <= en; j++){
            auto [child, idc] = g[i][j];
            if(done[idc] == -1) self(child, i, idc, self);
            done[id] = (done[id] + done[idc] + 1) % MOD;
        }
        res[i][x] = done[id];
    };
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(auto &[child,id] : g[i]){
            if(done[id] == -1) func(child, i, id, func);
            ans = (ans + done[id] + 1) % MOD;
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