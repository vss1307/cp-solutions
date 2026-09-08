/*
 * Author: vss_1307
 * Created: 2025-12-11 20:06:06
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
    stack <int> stk;
    int ans = 0;
    for(int i = n-1; i > -1; i--){
        while(stk.size() && stk.top() < v[i]){
            stk.pop();
            ans++;
        }
        stk.push(v[i]);
    }
    cout << ans << nl;
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