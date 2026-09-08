/*
 * Author: vss_1307
 * Created: 2026-05-02 17:32:19
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    vector <vector <int> > v(3, vector <int> (6));
    for(auto &x : v) for(auto &y : x) cin >> y;
    vector <int> p = {0,1,2};
    double den = 6 * 6 * 6;
    double fin = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                int x = (v[0][i] == 4) + (v[1][j] == 4) + (v[2][k] == 4);
                int y = (v[0][i] == 5) + (v[1][j] == 5) + (v[2][k] == 5);
                int z = (v[0][i] == 6) + (v[1][j] == 6) + (v[2][k] == 6);
                if(x == y && y == z && z == 1) fin++;
            }
        }
    }
    cout << fixed << setprecision(10) << fin/den << nl;
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