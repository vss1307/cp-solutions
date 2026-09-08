/*
 * Author: vss_1307
 * Created: 2026-03-07 17:55:16
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 10007;
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

ll exp(ll base, ll power, ll mod){
    ll res = 1;
    while(power){
        if(power&1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        power >>= 1;
    }
    return res;
}

ll toadd(ll c, ll l, ll mod){
    ll nm = mod * 9;
    ll res = exp(10, l, nm);
    res = (res - 1 + nm) % nm;
    res = mul(res, c, nm);
    return res/9;
}

void solve(){ 
    ll k, m; cin >> k >> m;
    ll ans = 0;
    ll n = 0, r = 0;
    for(int i = 0; i < k; i++){
        ll c, l; cin >> c >> l;
        n = mul(n, exp(10, l, MOD), MOD);
        r = mul(r, exp(10, l, m), m);
        n = (n + toadd(c, l, MOD)) % MOD;
        r = (r + toadd(c, l, m)) % m;
    }
    ll x = (((n-r) % MOD) + MOD) % MOD;
    x = mul(x, exp(m, MOD-2, MOD), MOD);
    cout << x << nl;
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