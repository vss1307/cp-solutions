/*
 * Author: vss_1307
 * Created: 2026-01-03 17:35:56
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e7 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <ll> ans(MAXN);

void solve(){ 
    ll n; cin >> n;
    ll sz = 0;
    for(ll i = 1; i*i < MAXN; i++){
        for(ll j = i+1; i * i + j * j < MAXN; j++){
            ans[i * i + j * j]++;
            if(ans[i * i + j * j]==1) sz++;
            else sz--;
        }
    }
    cout << sz << nl;
    for(int i = 1; i <= n; i++) if(ans[i] == 1) cout << i << ' ';
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