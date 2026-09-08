/*
 * Author: vss_1307
 * Created: 2025-12-07 21:51:14
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
    int p = 0;
    while((1ll<<p) <= max(n, x)) p++;
    int tot = 0;
    vector <ll> ans(n);
    for(int i = 0; i < n-2 + (n&1); i++){
        ans[i] = (1ll<<p) + i;
        tot ^= ans[i];
    }
    if(n%2 == 0){
        if(tot == x && n > 2){
            tot ^= ans[n-3];
            ans[n-3] += 1;
            tot ^= ans[n-3];
        }
        else if(tot == x){
            cout << "NO" << nl;
            return;
        }
        ans[n-2] = 0;
    }
    ans[n-1] = tot^x;
    cout << "YES" << nl;
    for(auto &k : ans) cout << k << ' ';
    cout << nl;
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