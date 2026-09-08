/*
 * Author: vss_1307
 * Created: 2025-12-09 19:40:48
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
    ll l = 0, r = n*n;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += min(n, mid/i);
        }
        if(cnt >= n*n/2 + 1) r = mid;
        else l = mid;
    }
    cout << r << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    solve();
}