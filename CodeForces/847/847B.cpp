/*
 * Author: vss_1307
 * Created: 2025-12-10 00:29:29
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector<vector<ll> > ans;
    for(int i = 0; i < n; i++){
        ll l = -1, r = ans.size();
        while(r - l > 1){
            ll mid = (r + l) >> 1;
            if(ans[mid].back() < v[i]) r = mid;
            else l = mid;
        }
        if(r == ans.size()) ans.push_back({v[i]});
        else ans[r].push_back(v[i]);
    }
    for(auto &x : ans){
        for(auto &y : x) cout << y << ' ';
        cout << nl;
    }
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