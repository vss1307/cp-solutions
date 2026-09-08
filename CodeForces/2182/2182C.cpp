/*
 * Author: vss_1307
 * Created: 2026-01-02 19:10:18
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
    vector <pair <ll, ll> > a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    // for(auto &x : a) cout << x.first << ' '; cout << nl;
    // for(auto &x : b) cout << x.first << ' '; cout << nl;
    // for(auto &x : c) cout << x.first << ' '; cout << nl;
    ll ans = 0;
    vector <ll> bc(n);
    ll ansb = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(b[i].first >= c[j].first) continue;
            ll x = c[j].second-b[i].second;
            if(x < 0) x += n;
            bc[x]++;
            if(bc[x] == n) ansb += n;
        }
    }
    // for(auto &x : bc) cout << x << ' '; cout << nl;
    vector <ll> ab(n);
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(a[i].first >= b[j].first) continue;
            ll x = b[j].second-a[i].second;
            if(x < 0) x += n;
            ab[x]++;
            if(ab[x] == n) ans += ansb;

        }
    }
    // for(auto &[x,y] : mab) cout << x << ' ' << y << nl;
    cout << ans << nl;
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    // sort(c.begin(), c.end());
    // ll ans = 0;
    // for(int i = 0; i < n; i++){
    //     ll j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    //     for(; j < n; j++){
    //         ll k = upper_bound(c.begin(), c.end(), b[j]) - c.begin();
    //         cout << k << nl;
    //         ans += n - k;
    //     }
    // }
    // cout << ans << nl;
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