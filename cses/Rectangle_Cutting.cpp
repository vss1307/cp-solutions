/*
 * Author: vss_1307
 * Created: 2025-12-27 13:08:36
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll a, b; cin >> a >> b;
    if(b < a) swap(a,b);
    vector <vector <ll> > v(a+1, vector <ll> (b+1, INT_MAX));
    v[0][0] = 0;
    for(int i = 1; i <= a; i++) v[i][i] = 0;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= b; k++){
                if(i+k <= a) v[i+k][j] = min(v[i][j] + v[k][j] + 1, v[i+k][j]);
                if(j+k <= b) v[i][j+k] = min(v[i][j] + v[i][k] + 1, v[i][j+k]);
            }
            // cout << i << ' ' << j << nl;
            // if(i+j <= a) v[i+j][i] = min(v[i][j] + 1, v[i+j][j]);
            // if(i+j <= b) v[i][i+j] = min(v[i][j] + 1, v[i][i+j]);
        }
    }
    // for(auto &x : v){
    //     for(auto &y : x) cout << y << ' '; cout << nl;
    // }
    cout << v[a][b] << nl;
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