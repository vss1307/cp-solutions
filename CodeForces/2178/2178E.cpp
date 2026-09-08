/*
 * Author: vss_1307
 * Created: 2025-12-27 21:37:58
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll q(ll l, ll r){
    cout << "? " << l << ' ' << r << endl;
    ll res; cin >> res;
    return res;
}

ll func(ll l, ll r, ll tot_sum){
    if(r==l) return tot_sum;
    ll lo = l, hi = r;
    while(hi - lo > 1){
        ll mid = (hi + lo) >> 1;
        ll sum = q(l, mid);
        if(sum <= tot_sum/2) lo = mid;
        else hi = mid;
    }
    if(hi - l <= r - lo) return func(l, lo, tot_sum/2);
    return func(hi, r, tot_sum/2);
}


void solve(){ 
    ll n; cin >> n;
    ll tot_sum = q(1, n);
    ll ans = func(1, n, tot_sum);
    cout << "! " << ans << endl;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    int te; cin >> te;
    while (te--)
        solve();
}