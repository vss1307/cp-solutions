/*
 * Author: vss_1307
 * Created: 2026-02-14 17:41:30
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, h, w; cin >> h >> w >> n;
    vector <array<ll, 3> > v(n);
    map <ll, multiset <array<ll, 2> > > mh, mv;
    ll ih = -1, iw = -1;
    for(int i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        if(x == h) ih = i;
        if(y == w) iw = i;
        mh[x].insert({y,i});
        mv[y].insert({x,i});
        v[i] = {x,y,i};
    }
    sort(v.begin(), v.end());
    pair <ll ,ll> cur = {h, w};
    vector <pair <ll, ll> > ans(n, {-1,-1});
    while(cur.first && cur.second){
        if(mh.find(cur.first) != mh.end()){
            auto s = mh[cur.first];
            for(auto &[x,y] : s){
                if(ans[y].first != -1) continue;
                cur.second -= x;
                ans[y] = {0, cur.second};
            }
            mh.erase(cur.first);
        }
        // cout << cur.first << ' ' << cur.second << nl;
        if(mv.find(cur.second) != mv.end()){
            auto s = mv[cur.second];
            for(auto &[x,y] : s){
                if(ans[y].second != -1) continue;
                cur.first -= x;
                ans[y] = {cur.first, 0};
            }
            mv.erase(cur.second);
        }
        // cout << cur.first << ' ' << cur.second << nl;
    }
    for(auto &[x,y] : ans) cout << x+1 << ' ' << y+1 << nl;
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