/*
 * Author: vss_1307
 * Created: 2025-12-27 20:19:19
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
    ll ans = 0;
    if(v[0] >= 0){
        ll mx = INT_MIN;
        for(int i = 0; i < n; i++){
            ans += abs(v[i]);
        }
        ll j = n-1;
        while(j >= 0 && v[j] <= 0) mx = max(mx, v[j--]);
        if(j == n-1) cout << ans - v.back() << nl;
        else cout << ans - min(abs(mx), abs(v[j])) << nl;
        return;
    }
    ll mx = INT_MIN;
    ll sum = v[0];
    for(int i = 1; i < n; i++){
        sum += abs(v[i]);
    }
    ll j = n-1;
    while(j >= 1 && v[j] <= 0) mx = max(mx, v[j--]);
    if(j == n-1) sum -= abs(v.back());
    else sum -= min(abs(mx), abs(v[j]));
    ll s1 = 0;
    for(int i = 1; i < n; i++) s1 -= v[i];
    cout << max(s1, sum) << nl;
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