/*
 * Author: vss_1307
 * Created: 2026-05-23 20:16:02
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
    int tog = 0;
    vector <ll> ans;
    for(int i = n-1; i >= 0; i--){
        if((v[i] > 0 && !tog) || (v[i] < 0 && tog)){
            ans.push_back(i);
            tog ^= 1;
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x+1 << ' ';
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