/*
 * Author: vss_1307
 * Created: 2026-08-25 22:36:10
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    map <ll, ll> mp;
    map <ll, ll> freq;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]] = i;
        freq[v[i]]++;
    }
    // for(auto &[x, y] : freq) cout << x << ' ' << y << nl;
    ll ans = 0;
    ll l = 0;
    ll r = 0;
    ll mx = 0;
    for(int i = 0; i < n; i++){
        r = max(r, mp[v[i]]);

        mx = max(mx, freq[v[i]]);

        if(i == r){
            ans += r - l + 1 - mx;
            l = i+1;
            mx = 0;
        }
    }
    cout << ans << nl;
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