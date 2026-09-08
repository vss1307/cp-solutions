/*
 * Author: vss_1307
 * Created: 2026-01-25 20:36:42
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
    ll i = 0;
    while(i < n && v[i] == n-i){
        cout << v[i] << ' ';
        i++;
    }
    ll j = n-1;
    while(j > i && v[j] != n-i) j--;
    ll k = j+1;
    while(j >= i) cout << v[j--] << ' ';
    while(k < n) cout << v[k++] << ' ';
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