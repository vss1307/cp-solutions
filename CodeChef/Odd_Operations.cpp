/*
 * Author: vss_1307
 * Created: 2026-01-14 20:05:01
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> dig(ll n){
    vector <ll> res;
    while(n){
        res.push_back(n%10);
        n/=10;
    }
    return res;
}


void solve(){ 
    int n; cin >> n;
    if(n < 10 && n%2==0){
        cout << -1 << nl; return;
    } 
    ll ans = 1;
    bool odd = false;
    auto v = dig(n);
    ll mx = 0;
    for(auto &d : v){
        if(d&1) odd = true;
        mx = max(mx, d);
    }
    while(!odd){
        n -= mx;
        ans++;
        v = dig(n);
        mx = 0;
        for(auto &d : v){
            if(d&1) odd = true;
            mx = max(mx, d);
        }
    }
    cout << ans - (n&1) << nl;
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