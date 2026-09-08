/*
 * Author: vss_1307
 * Created: 2025-12-10 20:07:22
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
    ll ans = 0;
    ll lis = 1, lds = 1;
    for(int i = 0; i < n-1; i++){
        if(v[i] > 1) lis++, lds++;
        else{
            if(lis == lds) lis++;
            else lds++;
        }
    }
    cout << (lis + lds) / 2 << nl;
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