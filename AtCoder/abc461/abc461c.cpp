/*
 * Author: vss_1307
 * Created: 2026-06-06 17:35:30
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k, m; cin >> n >> k >> m;
    map <ll, vector <ll> > mp;
    for(int i = 0; i < n; i++){
        ll c, v; cin >> c >> v;
        mp[c].push_back(v);
    }
    for(auto &[c,v] : mp){
        sort(v.begin(), v.end());
    }
    multiset <ll> ans;
    for(auto &[c,v] : mp){
        ans.insert(v.back());
    }
    ll s = 0;
    while(m){
        auto it = --ans.end();
        s += *(it);
        ans.erase(it);
        m--;
        k--;
    }
    for(auto &[c,v] : mp){
        for(int i = 0; i < v.size() - 1; i++) ans.insert(v[i]);
    }
    while(k){
        auto it = --ans.end();
        s += *(it);
        ans.erase(it);
        k--;
    }
    cout << s << nl;
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