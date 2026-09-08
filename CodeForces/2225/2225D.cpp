/*
 * Author: vss_1307
 * Created: 2026-04-21 20:21:09
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mul(ll a, ll b, ll mod){
    a%=mod,b%=mod;
    if(mod <= 1e9) return a * b % mod;
    if(mod <= 1ll * 1e12) return ((((a * (b>>20))%mod)<<20) + (a * (b&((1<<20) - 1)))) % mod;
    ll d = (ll)floor( (long double)a * b / mod + 0.5);
    ll res = (a * b - mod * d) % mod;
    if(res < 0) res += mod;
    return res;
}

void solve(){ 
    ll n, x; cin >> n >> x;
    ll a = x, b = x;
    ll c = n, d = n;
    for(; a <= n; a++){
        if((a&3) == 3) break;
    }
    for(; b <= n; b++){
        if((b&1) == 1 && (b&3) != 3) break;
    }
    for(; c >= x; c--){
        if((c&3) == 3) break;
    }
    for(; d >= x; d--){
        if((d&1) == 1 && (d&3) != 3) break;
    }
    // cout << a << ' ' << b << nl;
    // cout << c << ' ' << d << nl;
    ll e = (c > a? c - a : 0)/4 + 1;
    ll f = (d > b? d - b : 0)/4 + 1;
    if(c < x) e--;
    if(d < x) f--;
    // cout << e << ' ' << f << nl;
    ll even = x/2 + 1;
    if(even%2) cout << (mul((even/2 + 1),e, MOD) + mul((even/2), f, MOD)) % MOD << nl;
    else cout << mul(even/2, (e + f), MOD) << nl;
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