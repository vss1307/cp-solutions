/*
 * Author: vss_1307
 * Created: 2025-12-19 17:55:59
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    ll ans = 0;
    for(int i = 1; i < n; i+=2){
        int x = v[i-1];
        if(i+1 < n) x += v[i+1];
        if(v[i] >= x) continue;
        int red = x - v[i];
        if(i+1 < n){
            int y = min(red, v[i+1]);
            v[i+1] -= y;
            red -= y;
            ans += y;
        }
        int y = min(red, v[i-1]);
        v[i-1] -= y;
        red -= y;
        ans += y;
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