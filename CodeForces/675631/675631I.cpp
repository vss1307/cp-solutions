/*
 * Author: vss_1307
 * Created: 2026-03-01 18:42:58
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
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    n = min(n, 63);
    vector <vector <pair <int , int> > > d(31);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x = (v[i] ^ v[j]);
            x = __builtin_popcount(x);
            for(auto &[l,r] : d[x]){
                if(l != i && l != j && r != i && r != j){
                    cout << l+1 << ' ' << r+1 << ' ' << i+1 << ' ' << j+1 << nl;
                    return;
                }
            }
            d[x].push_back({i, j});
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