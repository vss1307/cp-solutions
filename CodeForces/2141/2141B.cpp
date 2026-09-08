/*
 * Author: vss_1307
 * Created: 2025-12-19 18:01:34
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
    set <int> a, b;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(a.find(x) != a.end()){
            a.erase(x);
            continue;
        }
        b.insert(x);
    }
    int ans = 0;
    if(a.size() < b.size() + 1) ans = 2 * a.size();
    else ans = 2 * b.size() + 1;
    cout << ans+1 << nl;
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