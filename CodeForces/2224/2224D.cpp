/*
 * Author: vss_1307
 * Created: 2026-05-06 12:28:59
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

ll merge(vector <ll>& v, ll l, ll r, vector <ll>& temp){
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    ll inv = merge(v, l, mid, temp) + merge(v, mid + 1, r, temp);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if(v[i] <= v[j]) temp[k++] = v[i++];
        else{
            temp[k++] = v[j++];
            inv += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = v[i++];
    while (j <= r) temp[k++] = v[j++];
    for (i = l; i <= r; i++) v[i] = temp[i];
    return inv;
}

ll count_inv(vector <ll>& v){
    if(v.size() == 0) return 0;
    ll n = v.size();
    vector <ll> temp(n);
    return merge(v, 0, n-1, temp);
}

void solve(){ 
    ll n; cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector <ll> v;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        vector<ll> row(n);
        vector<ll> col(n);
        for(int j = 0; j < n; j++){
            v.push_back(a[i] * b[j]);
            row[j] = a[i] * b[j];
            col[j] = a[j] * b[i];
        }
        ans -= count_inv(row) + count_inv(col);
    }
    ans = (ans + count_inv(v)) % MOD;
    ans = (ans + MOD) % MOD;
    // cout << ans << nl;
    // cout << fct[n] << nl;
    cout << mul(ans, exp(n * (n-1), MOD-2, MOD), MOD) << nl;
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