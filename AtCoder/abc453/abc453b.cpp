/*
 * Author: vss_1307
 * Created: 2026-04-15 10:17:59
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, x; cin >> n >> x;
    vector<int> v(n+1);
    for(auto &y : v) cin >> y;
    int last = v[0] - x;
    for(int i = 0; i < n+1; i++){
        if(abs(v[i] - last) >= x){
            cout << i << ' ' << v[i] << nl;
        last = v[i];
        }
    }
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