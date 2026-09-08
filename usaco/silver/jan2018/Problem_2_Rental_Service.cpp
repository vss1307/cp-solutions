/*
 * Author: vss_1307
 * Created: 2026-01-26 23:21:38
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m, r; cin >> n >> m >> r;
    vector <ll> c(n);
    for(auto &x : c) cin >> x;
    sort(c.begin(), c.end());
    priority_queue < pair <ll, ll> > pq;
    for(int i = 0; i < m; i++){
        ll p, q; cin >> p >> q;
        pq.push({q, p});
    }
    vector <ll> rent(r);
    for(auto &x : rent) cin >> x;
    sort(rent.rbegin(), rent.rend());
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < min(r, n); i++) sum += rent[i];
    for(int i = min(r, n); i < n; i++){
        while(pq.size() && c[i]){
            auto [y,z] = pq.top(); pq.pop();
            ll x = min(c[i], z);
            c[i] -= x;
            z -= x;
            sum += x * y;
            if(z) pq.push({y,z});
        }
    }
    ans = sum;
    for(ll i = min(r, n) -  1; i > -1; i--){
        while(pq.size() && c[i]){
            auto [y,z] = pq.top(); pq.pop();
            ll x = min(c[i], z);
            c[i] -= x;
            z -= x;
            sum += x * y;
            if(z) pq.push({y,z});
        }
        sum -= rent[i];
        ans = max(ans, sum);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // freopen("rental.in", "r", stdin);
    // freopen("rental.out", "w", stdout);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    // int te; cin >> te;
    // while (te--)
        solve();
}