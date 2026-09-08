/*
 * Author: vss_1307
 * Created: 2026-03-29 09:38:11
 */
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds; 
template<typename T>
using indexed_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
const int MOD = 1e9 + 7;
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

bool witness(ll a, ll p){
    ll d = p-1;
    int t = 0;
    while(d%2 == 0) d/=2,t++;
    ll x = exp(a, d, p);
    while(t--){
        ll y = mul(x, x, p);
        if(y == 1 && x!= 1 && x!=p-1) return true;
        x = y;
    }
    return (x!=1);
}

bool miller_rabin(ll p){
    if(p < 2) return false;
    vector <int> c_int = {2, 3, 5, 7};
    vector <int> c_ll = {2, 3, 5, 7, 11, 13, 15, 17, 23, 27, 31, 37};    
    for(auto &a : c_ll){
        if(p == a) return true;
        if(witness(a, p)) return false;
    }
    return true;
}

void solve(){ 
    indexed_set <ll> st;
    for(ll i = 1; i <= 1e9; i *= 2) st.insert(i);
    auto len = [](ll x)->ll{
        ll res = 0;
        while(x){
            x/=10;
            res++;
        }
        return res;
    };
    for(auto &x : st){
        for(auto it = st.begin(); it != st.end(); it++){
            if(len(x) + len(*it) >= 10) break;
            ll y = x * exp(10, len(*it), MOD) + *it;
            if(y <= 1e9) st.insert(y);
        }
    }
    ll n; cin >> n;
    cout << *st.find_by_order(n-1) << nl;
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