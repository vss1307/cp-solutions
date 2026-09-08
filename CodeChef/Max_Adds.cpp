/*
 * Author: vss_1307
 * Created: 2025-12-17 20:28:25
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n,m; cin >> n >> m;
    vector <ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector <ll> suff(n+1);
    for(int i = n-1; i >=0; i--) suff[i] = suff[i+1] + b[i];
    pair <ll, ll> mx = {suff[0], 0};
    for(int i = 0; i < n; i++){
        if(suff[i+1] + a[i] > mx.first){
            mx = {suff[i+1] + a[i], i+1};
        }
    }
    ll ans = mx.first*m;
    if(mx.second != 0){
        ll i = mx.second;
        ll y = a[i-1] - (suff[0] - suff[i]);
        m = max(0ll, m - y);
    }
    ans += (m) * (m+1)/2;
    cout << ans << nl;
    return;
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