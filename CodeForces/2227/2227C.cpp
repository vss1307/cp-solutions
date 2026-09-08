/*
 * Author: vss_1307
 * Created: 2026-05-03 17:22:14
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    vector <vector <int> > ans(3);
    vector <ll> a;
    for(auto &x : v){
        if(x%2 == 0 && x%3 != 0) ans[0].push_back(x);
        else if(x%2 != 0 && x%3 == 0) ans[1].push_back(x);
        else if(x%2 == 0 && x%3 == 0) ans[2].push_back(x);
        else a.push_back(x);
    }
    for(auto &x : ans[2]) cout << x << ' ';
    for(auto &x : ans[0]) cout << x << ' ';
    for(auto &x : a) cout << x << ' ';
    for(auto &x : ans[1]) cout << x << ' ';
    cout << nl;
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