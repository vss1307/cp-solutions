/*
 * Author: vss_1307
 * Created: 2026-01-14 20:32:41
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
    string p,q,r; cin >> p >> q >> r;
    ll x = 0, y = 0;
    vector <vector <vector <ll>> > v(2, vector <vector <ll>> (2));
    for(int i = 0; i < n; i++){
        if(r[i] != q[i]){
            if(q[i] == '1'){
                if(v[p[i]-'0'][0].size()){
                    v[p[i]-'0'][0].pop_back();
                    continue;
                }
                x++;
                v[p[i]-'0'][1].push_back(i);
            }
            else {
                if(v[p[i]-'0'][1].size()){
                    v[p[i]-'0'][1].pop_back();
                    continue;
                }
                y++;
                v[p[i]-'0'][0].push_back(i);
            }
        }
    }
    cout << max(x,y) << nl;
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