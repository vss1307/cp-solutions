/*
 * Author: vss_1307
 * Created: 2026-03-14 17:33:26
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int h, w, q; cin >> h >> w >> q;
    vector <vector <bool> > v(h, vector <bool> (w, true));
    while(q--){
        int t; cin >> t;
        int x; cin >> x;
        int ans = 0;
        if(t == 1){
            for(int i = h-x; i < h; i++){
                for(int j = 0; j < w; j++){
                    ans += v[i][j];
                    v[i][j] = false;
                }
            }
            h -= x;
        }
        if(t == 2){
            for(int i = w-x; i < w; i++){
                for(int j = 0; j < h; j++){
                    ans += v[j][i];
                    v[j][i] = false;
                }
            }
            w -= x;
        }
        cout << ans << nl;
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