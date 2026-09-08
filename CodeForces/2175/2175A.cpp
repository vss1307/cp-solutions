/*
 * Author: vss_1307
 * Created: 2025-12-06 13:47:38
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
    set <int> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    ll x = s.size();
    while(s.find(x) == s.end()){
        s.insert(x);
        x = s.size();
    }
    cout << s.size() << nl;
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