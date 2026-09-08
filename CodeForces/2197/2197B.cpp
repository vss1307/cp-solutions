/*
 * Author: vss_1307
 * Created: 2026-02-11 20:23:41
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
    vector <ll> a(n), p(n);
    for(auto &x : p) cin >> x;
    for(auto &x : a) cin >> x;
    ll i = 0, j = 0;
    while(i < n && j < n){
        if(p[i] == a[j]) j++;
        else i++;
    }
    if(j == n) cout << "YES" << nl;
    else cout << "NO" << nl;
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