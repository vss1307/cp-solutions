/*
 * Author: vss_1307
 * Created: 2026-08-15 17:30:17
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int a, b; cin >> a >> b;
    if(a + b == 9 || a - b == 9 || a * b == 9 || (a % b == 0 && a / b == 9)) cout << "Nine" << nl;
    else cout << "Nein" << nl;
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