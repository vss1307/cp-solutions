/*
 * Author: vss_1307
 * Created: 2025-12-13 21:15:40
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll l = 0, r = *max_element(v.begin(), v.end()) + 1;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll cs = 0;
        vector <ll> pref(n+1);
        for(int i = 0; i < n; i++) pref[i+1] = pref[i] + (v[i]<mid ? -1 : 1);
        ll mn = 0;
        bool check = false;
        for(int i = k; i <= n; i++){
            mn = min(mn, pref[i-k]);
            if(pref[i] - mn > 0) check = true;
        }
        // ll i = 0, j = 0;
        // while(j < k){
        //     if(v[j] < mid) cs++;
        //     j++;
        // }
        // ll dif = 0;
        // while(j < n && cs >= (j - i)/2){
        //     if(v[j-k] < mid) dif++;
        //     else dif--;
        //     if(v[j] < mid) cs++;
        //     j++;
        //     while(j-i > k && dif >= 0){
        //         if(v[i] < mid) cs--, dif--;
        //         else dif++;
        //         i++;
        //     }
        // }
        if(check) l = mid;
        else r = mid;
    }
    cout << l << nl;
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