/*
 * Author: vss_1307
 * Created: 2025-12-24 21:33:58
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector <ll> suff1(n+1), suff2(n+1);
    vector <ll> p(n);
    for(ll i = 0; i < n; i++) p[i] = max(i, i - v[i] + 1);
    for(ll i = n-1; i > -1; i--) suff1[i] = (suff1[i+1] + max(v[i], 1ll)) % MOD;
    for(ll i = n-1; i > -1; i--) suff2[i] = (suff2[i+1] + max(v[i], 1ll) * (n-i)) % MOD;
    ll ans = 0;
    vector <ll> dp(n+1);
    ll l1 = n;
    ll last_i = n;
    for(ll i = n-1; i > -1; i--){
        if(l1 <= p[i]){
            dp[i] = dp[last_i];
        }
        else{
            l1 = p[i];
            last_i = i;
            dp[i] = suff2[l1] % MOD;
        }
    }
    for(auto &x : dp) ans = (ans + x) % MOD;
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