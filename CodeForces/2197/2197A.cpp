/*
 * Author: vss_1307
 * Created: 2026-02-11 20:08:59
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
    auto dig = [](ll y)->ll{
        ll res = 0;
        while(y){
            res += y%10;
            y /=10;
        }
        return res;
    };
    ll s = 0;
    for(ll i = n; i < n + 10 * dig(n); i++){
        if(i - dig(i) == n) s++;
    }    
    cout << 10 * (s>0) << nl;
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