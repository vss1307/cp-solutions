/*
 * Author: vss_1307
 * Created: 2026-09-04 13:56:21
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int a = v[0], c = v[n-1];
    for(int b = 1; b < n-1; b++){
        if(a + v[b] <= c){
            cout << 1 << ' ' << b+1 << ' ' << n << nl; return;
        }
    }
    cout << -1 << nl;
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