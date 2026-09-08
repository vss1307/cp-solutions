/*
 * Author: vss_1307
 * Created: 2026-04-13 20:14:56
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
    ll m; cin >> m;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    for(ll i = 0; i < n;){
        ll j = i;
        while(j < n && v[j] == v[i]) j++;
        ll same = j - i;
        if(same >= m){
            cout << "NO" << nl; return;
        }
        i = j;
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