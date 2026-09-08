/*
 * Author: vss_1307
 * Created: 2026-02-07 17:32:35
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    ll ans = 0;
    auto dig_sum = [](ll i) -> ll{
        ll res = 0;
        while(i){
            res += i%10;
            i/=10;
        }
        return res;
    };
    for(int i = 1; i <= n; i++){
        if(dig_sum(i) == k) ans++;
    }
    cout << ans << nl;
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