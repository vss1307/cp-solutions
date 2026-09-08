/*
 * Author: vss_1307
 * Created: 2026-01-07 20:18:23
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(),v.end());
    set <ll> st;
    for(int i = 0; i < n && st.size() < k-1; i++){
        st.insert(v[i]);
    }
    cout << *(--st.end()) + 1 << nl;
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