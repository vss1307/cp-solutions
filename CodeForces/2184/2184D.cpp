/*
 * Author: vss_1307
 * Created: 2026-01-16 15:50:24
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> fct(100);
vector <ll> invfct(100);

ll mul(ll a, ll b, ll mod){
    a%=mod,b%=mod;
    if(mod <= 1e9) return a * b % mod;
    if(mod <= 1ll * 1e12) return (((a * (b>>20))%mod)<<20) + (a * (b&((1<<20) - 1))) % mod;
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

ll ncr(ll n, ll r){
    if(n < 0 || r > n) return 1;
    ll den = mul(invfct[r], invfct[n-r], MOD);
    return mul(den, fct[n], MOD);
}

void solve(){ 
    ll n, k; cin >> n >> k;
    ll x = 0;
    ll ans = 0;
    while(n > (1ll << x)){
        ll y = x;
        x++;
        ll req1 = k - y - 1;
        if(req1 < 0) break;
        for(int i = 0; i <= min(y, req1); i++) ans += ncr(y, i);
    }
    if(k > __builtin_ctz(n)) ans++;
    cout << n - ans << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    fct[0] = 1;
    invfct[0] = exp(1, MOD - 2, MOD);
    for(int i = 1; i < 50; i++){
        fct[i] = mul(i, fct[i-1], MOD);
        invfct[i] = exp(fct[i], MOD - 2, MOD);
    }
    int te; cin >> te;
    while (te--)
        solve();
}