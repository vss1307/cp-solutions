/*
 * Author: vss_1307
 * Created: 2026-03-29 09:32:33
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, m; cin >> n >> m;
    vector <int> c(m), f(m);
    for(int i =0 ; i < n; i++){
        int a, b; cin >> a >> b;
        c[a-1]++;
        f[b-1]++;
    }
    for(int i = 0; i < m; i++){
        cout << f[i] - c[i] << nl;
    }
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