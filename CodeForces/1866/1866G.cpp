/*
 * Author: vss_1307
 * Created: 2025-12-14 18:34:27
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
    vector <ll> v(n), d(n);
    for(auto &x : v) cin >> x;
    for(auto &x : d) cin >> x;
    ll l = -1, r = 1e14 + 1;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        vector <pair <ll, ll> > st;
        priority_queue <pair <ll, ll> , vector <pair <ll, ll> >, greater <pair <ll, ll> > > pq;
        // auto temp = v;
        for(int i = 0; i < n; i++) st.push_back({i - d[i], i});
        sort(st.begin(), st.end());
        ll j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && st[j].first <= i){
                auto [x, y] = st[j++];
                if(v[y]) pq.push({y + d[y], v[y]});
            }
            ll cap = 0;
            while(pq.size() && cap < mid){
                auto [x, y] = pq.top();
                if(x < i) break;
                pq.pop();
                ll fill = min(mid - cap, y);
                cap += fill;
                y -= fill;
                if(y) pq.push({x, y});
            }
        }
        if(pq.size()) l = mid;
        else r = mid;
    }
    cout << r << nl;
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