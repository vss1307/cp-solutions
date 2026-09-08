/*
 * Author: vss_1307
 * Created: 2026-01-21 20:01:26
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
    for(auto &x : v) cin >> x;
    int ans = n;
    for(int i = n-1; i > -1; i--){
        if(v[i] == i+1) ans--;
        else{
            ans = v[i];
            break;
        }
    }
    cout << ans << nl;
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