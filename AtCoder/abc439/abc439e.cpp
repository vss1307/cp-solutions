/*
 * Author: vss_1307
 * Created: 2026-01-03 18:21:34
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
    vector <pair <ll, ll> > v(n);
    for(auto &x : v) cin >> x.first >> x.second;
    sort(v.begin(), v.end(), [](const auto &a, const auto &b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });
    vector <ll> lis;
    for(int i = 0; i < n; i++){
        ll x = v[i].second;
        if(lis.size() == 0 || lis.back() < x) lis.push_back(x);
        else{
            auto j = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[j] = x;
        }
    }
    cout << lis.size() << nl;
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