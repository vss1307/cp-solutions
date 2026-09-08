/*
 * Author: vss_1307
 * Created: 2026-07-18 17:59:06
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    vector <pair <ll, ll> > v(4);
    for(auto &x : v) cin >> x.first >> x.second;
    ll a = v[1].first - v[0].first;
    ll b = v[1].second - v[0].second;
    ll c = (v[0].first*v[0].first + v[0].second*v[0].second) - (v[1].first*v[1].first + v[1].second*v[1].second);
    ll a1 = v[3].first - v[2].first;
    ll b1 = v[3].second - v[2].second;
    ll c1 = (v[2].first*v[2].first + v[2].second*v[2].second) - (v[3].first*v[3].first + v[3].second*v[3].second);
    if(a*b1 != b * a1 || (a*b1 == b * a1 && b1*c == b * c1 && a1*c == a * c1)) cout << "Yes" << nl;
    else cout << "No" << nl;
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