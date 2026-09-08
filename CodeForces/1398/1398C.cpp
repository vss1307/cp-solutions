/*
 * Author: vss_1307
 * Created: 2026-09-04 13:52:50
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
    vector<int> v(n+1);
    map <int, int> freq;
    freq[0]++;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        c -= '0';
        v[i+1] = v[i] + c - 1;
        ans += freq[v[i+1]];
        freq[v[i+1]]++;
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