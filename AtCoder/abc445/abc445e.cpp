/*
 * Author: vss_1307
 * Created: 2026-02-14 18:22:22
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

ll exp(ll base, ll power, ll mod){
    ll res = 1;
    while(power){
        if(power&1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        power >>= 1;
    }
    return res;
}

void solve(){ 
    ll n; cin >> n;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector <ll> prefl(n+1, 1), suffl(n+1, 1);
    for(int i = 0; i < n; i++){
        prefl[i+1] = lcm(prefl[i], v[i]) % MOD;
    }
    for(int i = n-1; i > -1; i--){
        suffl[i] = lcm(suffl[i+1], v[i]) % MOD;
    }
    for(int i = 0; i < n; i++){
        ll over = lcm(prefl[i], suffl[i+1]) % MOD;
        cout << over << ' ';
    }
    cout << nl;
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