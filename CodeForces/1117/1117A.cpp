/*
 * Author: vss_1307
 * Created: 2025-12-09 22:43:35
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
    for(int i = 0; i < n; i++) cin >> v[i];
    ll mx = *max_element(v.begin(), v.end());
    ll l = -1, r = -1;
    ll cl = -1, cr = -1;
    for(int i = 0; i < n;){
        if(v[i] != mx){
            i++;
            continue;
        }
        int j = i;
        while(j < n && v[j] == mx) j++;
        if(j - i > r - l) l = i, r = j;
        i = j;
    }
    cout << r - l << nl;
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