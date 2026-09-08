/*
 * Author: vss_1307
 * Created: 2026-01-27 00:22:11
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    vector <pair <ll, ll> > v(n);
    for(auto &x : v) cin >> x.first >> x.second;
    sort(v.begin(),v.end());
    vector < pair <ll, ll> > val;
    auto bs = [&](ll c1, ll c2)->ll{
        ll l = -1, r = val.size();
        while(r - l > 1){
            ll mid = (r + l) >> 1;
            if(val[mid].first >= c1 && val[mid].second >= c2) r = mid;
            else l = mid;
        }
        return r;
    };
    for(int i = n-1; i > -1; i--){
        auto [x,y] = v[i];
        auto j = bs(x + y, x - y);
        if(j == val.size()) val.push_back({x + y, x - y});
    }
    cout << val.size() << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    // int te; cin >> te;
    // while (te--)
        solve();
}