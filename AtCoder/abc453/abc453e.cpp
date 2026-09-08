/*
 * Author: vss_1307
 * Created: 2026-04-15 15:56:30
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 2e5 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll fct[MAXN];
ll invfct[MAXN];
vector <ll> a[MAXN];
vector <ll> b[MAXN];

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

ll ncr(ll n, ll r){
    if(n < r || r < 0) return 0;
    return mul(fct[n] * invfct[r], invfct[n-r], MOD);
}

void solve(){ 
    cin >> n;
    vector <int> ina(n), inb(n);
    ll cnt[2][2] = {0};
    cnt[0][0] = n;
    for(int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        a[l].push_back(i);
        a[r+1].push_back(i);
        b[n-r].push_back(i);
        b[n-l+1].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < n+1; i++){
        for(auto &x : a[i]){
            cnt[ina[x]][inb[x]]--;
            ina[x] ^= 1;
            cnt[ina[x]][inb[x]]++;
        }
        for(auto &x : b[i]){
            cnt[ina[x]][inb[x]]--;
            inb[x] ^= 1;
            cnt[ina[x]][inb[x]]++;
        }
        // cout << i << ' ' << none << ' ' << ga << ' ' << gb << ' ' << both << nl;
        if(cnt[0][0] || cnt[0][0] == n || cnt[1][0] > i || cnt[0][1] > n-i) continue;
        ans = (ans + ncr(cnt[1][1], i-cnt[1][0])) % MOD;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    fct[0] = 1;
    invfct[0] = exp(fct[0], MOD-2, MOD);
    for(int i = 1; i < MAXN; i++){
        fct[i] = mul(fct[i-1], i, MOD);
        invfct[i] = exp(fct[i], MOD-2, MOD);
    }
    // int te; cin >> te;
    // while (te--)
        solve();
}