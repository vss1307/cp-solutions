/*
 * Author: vss_1307
 * Created: 2026-03-29 21:00:51
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll spf[MAXN];
vector <ll> primes;

void seive(){
    for(ll i = 0; i < MAXN; i++) spf[i] = i;
    for(ll i = 2; i < MAXN; i++){
        if(spf[i] == i) primes.push_back(i);
        for(auto &p : primes){
            if(p *1ll * i >= MAXN) break;
            spf[p * i] = p;
            if(i % p == 0) break;
        }
    }
}

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
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(auto &x : b) cin >> x;
    ll ans = 0;
    vector<pair<ll, ll>> r;
    for(ll i = 0; i < n; i++){
        ll rem = 1;
        ll k1 = a[i];
        ll k2 = a[i];
        if(i+1 < n){
            k1 = a[i]/ __gcd(a[i], a[i+1]);
        }
        if(i-1 > -1){
            k2 = a[i]/ __gcd(a[i], a[i-1]);
        }
        rem = __gcd(k1, k2);
        if(rem > 1 && a[i]/rem <= b[i]){
            ans++;
            a[i]/=rem;            
        } 
        else if(rem == 1){
            ll q = upper_bound(primes.begin(), primes.end(), (b[i])/a[i]) - primes.begin();
            if(q != 0) r.push_back({primes[q-1], i});
        }
    }
    sort(r.begin(), r.end());
    for(auto &[q,i] : r){
        for(auto &p : primes){
            if(a[i] * p > b[i]) break;
            ll x1 = 1, x2 = a[i], x3 = 1;
            ll y1 = 0, y2 = 0, y3 = 0;
            if(i+1 < n) x3 = a[i+1];
            if(i-1 > -1) x1 = a[i-1];
            while(x1 > 1 && x1%p == 0){
                x1/=p, y1++;
            }
            while(x2 > 1 && x2%p == 0){
                x2/=p, y2++;
            }
            while(x3 > 1 && x3%p == 0){
                x3/=p, y3++;
            }
            if(y2+1 > max(y1, y3)){
                ans++;
                a[i] *= p;
            }
            break;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    seive();
    int te; cin >> te;
    while (te--)
        solve();
}