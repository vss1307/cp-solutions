/*
 * Author: vss_1307
 * Created: 2026-01-06 19:05:10
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
template<typename T>
using indexed_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

void solve(){ 
    int n; cin >> n;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;

    indexed_set <pair <ll, ll> > st;
    ll ans = 0;
    ll last = 0;
    for(int i = 1; i < n; i++){
        ll s = 0;
        for(int j = 0; j < i; j++){
            if(v[i] < v[j]) continue;
            s = (s + exp(2, i - j - 1, MOD)) % MOD;
        }
        ans = (ans + s) % MOD;
        // st.insert({v[i], i+1});
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