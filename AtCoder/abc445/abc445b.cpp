/*
 * Author: vss_1307
 * Created: 2026-02-14 17:32:06
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n;  cin >> n;
    vector <string> v(n);
    ll mx = 0;
    for(auto &x : v){
        cin >> x;
        mx = max(mx, (ll)x.size());
    }
    for(int i = 0; i < n; i++){
        ll y = mx - v[i].size();
        y /= 2;
        for(int j = 0; j < y; j++) cout << '.';
        cout << v[i];
        for(int j = 0; j < y; j++) cout << '.';
        cout << nl;
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