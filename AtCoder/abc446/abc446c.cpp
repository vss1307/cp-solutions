/*
 * Author: vss_1307
 * Created: 2026-02-21 17:37:11
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, d; cin >> n >> d;
    vector <ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    queue <pair <ll, ll> > q;
    for(int i = 0; i < n; i++){
        q.push({a[i], i});
        ll rem = b[i];
        while(rem){
            auto x = q.front();
            ll y = min(rem, x.first);
            rem -= y;
            q.front().first -= y;
            if(q.front().first == 0) q.pop();
        }
        while(q.size() && q.front().second <= i-d) q.pop();
    }
    ll ans = 0;
    while(q.size()){
        auto x = q.front().first; q.pop();
        ans += x;
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