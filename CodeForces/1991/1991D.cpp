/*
 * Author: vss_1307
 * Created: 2026-08-17 21:52:34
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
    if(n <= 5){
        cout << (n+2)/2 << nl;
        for(int i = 1; i <= n; i++) cout << (i+2)/2 << ' ';
    }
    else{
        cout << 4 << nl;
        // for(int i = 1; i <= 6; i++) cout << (i+2)/2 << ' ';
        for(int i = 1; i <= n; i++) cout << (i)%4 + 1 << ' ';
    }
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