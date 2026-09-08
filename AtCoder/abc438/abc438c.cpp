/*
 * Author: vss_1307
 * Created: 2025-12-27 17:46:19
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
    stack <pair <ll, ll> > stk;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(stk.size()){
            if(x == stk.top().first) stk.top().second++;
            else stk.push({x, 1});
            if(stk.top().second == 4) stk.pop();
        }
        else stk.push({x, 1});
    }
    ll ans = 0;
    while(stk.size()){
        ans += stk.top().second;
        stk.pop();
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