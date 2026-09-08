/*
 * Author: vss_1307
 * Created: 2025-12-10 19:14:41
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    ll k = n * n - m;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    ll l = 1, r = 2*v[n-1] + 1;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        // mid is the breaking point between the shakes, if shake sum is <= mid true, else false
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            auto j = upper_bound(v.begin(), v.end(), mid - v[i]) - v.begin();
            cnt += j;
        }
        if(cnt <= k) l = mid;
        else r = mid;
    }
    vector <ll> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] = pref[i] + v[i];
    ll cnt = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        auto j = upper_bound(v.begin(), v.end(), l - v[i]) - v.begin();
        cnt += j;
        sum += pref[j] + j * v[i];
    }
    sum += (k - cnt) * (l+1);
    cout << (2 * n) * pref[n] - sum << nl;
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