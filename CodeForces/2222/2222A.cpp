/*
 * Author: vss_1307
 * Created: 2026-04-25 20:06:59
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
    for(auto &x : v){
        cin >> x;
        x = 100/x;
    }
    sort(v.begin(), v.end());
    vector <int> ans(100 * n + 1, 1);
    for(auto &x : v){
        for(int i = 0; i < 100 * n + 1; i++){
            if(i%x == 0){
                ans[i] = 0;
                if(i+x < 100 * n + 1) ans[i+x] = 0;
            }
        }
    }
    for(auto &x : ans){
        if(x){
            cout << "No" << nl; return;
        }
    }
    cout << "Yes" << nl;
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