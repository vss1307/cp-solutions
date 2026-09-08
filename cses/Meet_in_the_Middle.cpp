/*
 * Author: vss_1307
 * Created: 2026-08-17 14:03:15
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void func(vector<ll>& a, const vector<int>& v){
    int n = v.size();
    for(int mask = 0; mask < (1ll<<n); mask++){
        ll s = 0;
        for(int i = 0; i < n; i++){
            if(((mask>>i)&1)) s += v[i];
        }
        a.push_back(s);
    }
}

void solve(){ 
    int n, s; cin >> n >> s;
    vector<int> a(n/2), b(n - n/2);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector<ll> v1, v2;
    func(v1, a);
    func(v2, b);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll ans = 0;
    for(auto &x : v1) ans += upper_bound(v2.begin(), v2.end(), s - x) - lower_bound(v2.begin(), v2.end(), s - x);
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