/*
 * Author: vss_1307
 * Created: 2026-01-23 20:05:55
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, h, l; cin >> n >> h >> l;
    if(h > l) swap(h, l);
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    ll j = n-1;
    while(j > 0 && v[j] > l) j--;
    ll ans = 0;
    for(int i = 0; i < j; i++){
        if(j > i) ans++, j--;
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