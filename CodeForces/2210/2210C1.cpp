/*
 * Author: vss_1307
 * Created: 2026-03-29 20:27:14
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 31623;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){ 
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    vector<map<ll,ll> > f(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(auto &x : b) cin >> x;
    ll ans = 0;
    for(int i = 0; i < n; i++){
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
        // cout << rem << ' ';
        if(rem > 1 && a[i]/rem <= b[i]) ans++;
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