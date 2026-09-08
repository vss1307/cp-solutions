/*
 * Author: vss_1307
 * Created: 2026-08-06 15:14:14
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
    vector <bool> a(n, false);
    for(auto &x : v) cin >> x;
    v.push_back(1e9);
    ll l = 0, r = 1e9;
    for(int i = 1; i < n; i++){
        if(v[i] < v[i-1]){
            if(!a[i-1]) l = max(l, v[i-1] - v[i]);
            else{ cout << "NO" << nl; return;}
        }
    }
    cout << "YES" << nl;
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