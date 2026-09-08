/*
 * Author: vss_1307
 * Created: 2026-03-03 16:38:40
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> fact(MAXN, 1);

void solve(){ 
    ll n, m; cin >> n >> m;
    map <pair <ll ,ll> , ll> dp;
    ll ans = (n + m - 1) / m;
    if(n == m || n%m == 1 || m == 1) ans--;
    cout << (ans + fact[m]) % MOD << nl;
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    int te; cin >> te;
    while (te--)
        solve();
}