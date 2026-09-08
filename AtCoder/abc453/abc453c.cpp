/*
 * Author: vss_1307
 * Created: 2026-04-15 10:20:35
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto &x  :v) cin >> x;
    ll best = 0;
    for(ll mask = 0; mask < (1ll<<n); mask++){
        double k = 0.5;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if((mask>>i)&1){
                if(k > 0 && k < v[i]) ans++;
                k -= v[i];
            }
            else{
                if(k < 0 && abs(k) < v[i]) ans++;
                k += v[i];
            }
        }
        best = max(ans, best);
    }
    cout << best << nl;
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