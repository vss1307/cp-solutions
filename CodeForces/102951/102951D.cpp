/*
 * Author: vss_1307
 * Created: 2026-01-20 16:38:47
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
const int inf = INT_MAX;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, q; cin >> n >> q;
    vector < array <ll, 3> > v(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin >> v[i][j];
        v[i][1]--;
    }
    sort(v.begin(), v.end());
    vector < array<ll, 3> > ans;
    ll val = 0;
    set <pair <ll, ll> > sr;
    ll j = 1;
    for(int i = 0; i < n; i++){
        val += v[i][2];
        if(v[i][2]){
            ll tval = v[i][2];
            auto it = sr.lower_bound({v[i][1], 0});
            if(it != sr.end() && it->first == v[i][1]){
                tval += it->second;
                sr.erase(it);
            }
            sr.insert({v[i][1], tval});
        }
        ll l = v[i][0];
        ll r = inf;
        if(i+1 < n) r = v[i+1][0]-1;
        while(sr.size() && sr.begin()->first <= r){
            if(val) ans.push_back({l, sr.begin()->first, val});
            val -= sr.begin()->second;
            l = sr.begin()->first + 1;
            sr.erase(sr.begin());
        }
        if(sr.size() && sr.begin()->first < r){
            r = min(r, sr.begin()->first);
            val -= sr.begin()->second;
            sr.erase(sr.begin());
        }
        if(val && l <= r) ans.push_back({l, r, val});
    }
    // for(auto &x : ans){
    //     for(auto &y : x) cout << y << ' '; cout << nl;
    // }
    vector <ll> pref(ans.size() + 1);
    for(int i = 0; i < ans.size(); i++) pref[i+1] = pref[i] + ans[i][2] * (ans[i][1] - ans[i][0] + 1);
    // for(auto &x : pref) cout << x << ' '; cout << nl;

    while(q--){
        ll l , r; cin >> l >> r;
        r = min(r, ans.back()[1] + 1);
        array<ll, 3> temp = {l, inf, inf};
        auto i = upper_bound(ans.begin(), ans.end(), temp) - ans.begin();
        temp[0] = r-1;
        auto j = upper_bound(ans.begin(), ans.end(), temp) - ans.begin();
        ll sum_r = 0;
        if(i != 0) sum_r += pref[i-1] + ans[i-1][2] * (l - ans[i-1][0]);
        ll req = 0;
        if(j != 0) req += pref[j-1] + ans[j-1][2] * (r - ans[j-1][0]);
        // cout << ans[j][0] << nl;
        // cout << i << ' ' << j << ' ' << sum_r << ' ' << req << nl;
        cout << req - sum_r << nl;
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