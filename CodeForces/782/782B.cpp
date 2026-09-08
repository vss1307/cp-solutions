/*
 * Author: vss_1307
 * Created: 2025-12-10 00:04:39
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
const double eps = 1e-6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector <ll> p(n), s(n);
    for(auto &x : p) cin >> x;
    for(auto &x : s) cin >> x;
    double l = -eps, r = 1e9+1;
    while(r - l > eps){
        double mid = (r + l)/2;
        double x1 = 0, x2 = 2e9;
        for(int i = 0; i < n; i++){
            double x = s[i] * mid;
            x1 = max(x1, p[i] - x);
            x2 = min(x2, p[i] + x);
        }
        if(x2 > x1 || abs(x2 - x1) <= eps) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(7) << r << nl;
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