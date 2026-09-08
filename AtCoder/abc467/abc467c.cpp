/*
 * Author: vss_1307
 * Created: 2026-07-18 17:36:19
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
    vector <int> a(n), b(n-1), c(n-1);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        c[i] = (a[i] + a[i+1]) % m;
        if(c[i] == b[i]) continue;
        if(i+1 == n-1) ans++;
        else{
            if(((a[i+2] + a[i+1])%m) == b[i+1]) a[i]++, ans++;
            else a[i+1]++, ans++;
        }
    }
    // for(auto &x: a) cout << x << ' '; cout << nl;
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