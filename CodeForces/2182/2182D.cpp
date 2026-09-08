/*
 * Author: vss_1307
 * Created: 2026-01-02 19:56:08
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

ll fct[100];
ll invfct[100];

ll ncr(ll n, ll r){
    if(r > n || r < 0 || n < 0) return 0;
    return mul(fct[n], mul(invfct[r], invfct[n-r], MOD), MOD);
}

void solve(){ 
    int n; cin >> n;
    ll z; cin >> z;
    vector <ll> a(n);
    for(auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    ll sum = accumulate(a.begin(), a.end(), z);
    ll r = sum / n;
    ll rem = sum % n;
    for(int i = 0; i < n; i++){
        if(a[i] > r) a[i] -= r;
        else if(a[i] <= r) z -= r - a[i], a[i] = 0;

        if(a[i] > 1 || z < 0){
            cout << 0 << nl; return;
        }
    }
    if(rem == 0){
        cout << fct[n] << nl; return;
    }
    if(rem == z){
        cout << mul(ncr(n, z), mul(fct[z], fct[n - z], MOD), MOD) << nl;
        return;
    }
    // for(auto &x : a) cout << x << ' '; cout << nl;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(!z){
                cout << 0 << nl; return;
            }
            z--, rem--;
        }
        else rem--, a[i]--;
        if(rem == z){
            cout << mul(ncr(n-i-1, z), mul(fct[i+1 + z], fct[n - 1 - i - z], MOD), MOD) << nl;
            return;
        }   
    }
    // ll curr_z = -1;
    // ll til = INT_MAX;
    // while(sum){
    //     if(sum == z && z <= (n)){
    //             cout << mul(ncr(n, z), mul(fct[z], fct[n - z], MOD), MOD) << nl;
    //             return;
    //         }

    //     for(int i = 0; i < n; i++){
    //         if(a[i] == 0){
    //             if(!z){
    //                 cout << 0 << nl; return;
    //             }
    //             z--, sum--;
    //         }
    //         else sum--, a[i]--;
    //         if(sum == z && z <= (n-i-1)){
    //             cout << mul(ncr(n-i-1, z), mul(fct[i+1 + z], fct[n - 1 - i - z], MOD), MOD) << nl;
    //             return;
    //         }
    //     }    
    // }
    cout << 0 << nl;
    // til = 0;
    // for(int j = i; j > n-(i+1); j--){
    //     if(a[j] == -1){
    //         til = j+1-i;
    //         break;
    //     }
    // }
    // cout << curr_z << ' ' << til << nl;
    // cout << mul(ncr(curr_z, til), mul(fct[n - curr_z + til], fct[curr_z - til], MOD), MOD) << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    fct[0] = 1;
    invfct[0] = exp(1, MOD - 2, MOD);
    for(int i = 1; i < 100; i++){
        fct[i] = mul(i, fct[i-1], MOD);
        invfct[i] = exp(fct[i], MOD - 2, MOD);
    }
    int te; cin >> te;
    while (te--)
        solve();
}