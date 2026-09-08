/*
 * Author: vss_1307
 * Created: 2025-12-27 17:51:05
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
    vector <ll> a(n), b(n), c(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    for(auto &x : c) cin >> x;
    vector <ll> suffc(n+1);
    for(int i = n-1; i > -1; i--) suffc[i] = suffc[i+1] + c[i];
    vector <ll> prefb(n+1);
    for(int i = 0; i < n; i++) prefb[i+1] = prefb[i] + b[i];
    vector <ll> prefc(n);
    for(int i = 1; i < n-1; i++){
        prefc[i] = prefb[i+1] + suffc[i+1];
    }
    for(int i = n-2; i > 0; i--) prefc[i] = max(prefc[i+1], prefc[i]);
    // for(auto &x : suffc) cout << x << ' '; cout << nl;
    // for(auto &x : prefb) cout << x << ' '; cout << nl;
    // for(auto &x : prefc) cout << x << ' '; cout << nl;

    ll sum = 0, ans = 0;
    for(int i = 0; i < n-1; i++){
        sum += a[i];
        ans = max(ans, sum + prefc[i+1] - prefb[i+1]);
        // cout << prefc[i+1] - prefb[i+1] << nl;
    }
    cout << ans << nl;
    // ll i = 0, j = n-1;
    // ll sum = a[i] + c[j];
    // for(int k = i+1; k < j; k++) sum += b[k];
    // ll ans = sum;
    // while(i < j-1){

    // }
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