/*
 * Author: vss_1307
 * Created: 2026-05-06 11:38:44
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    set <ll> st;
    for(int i = 0; i < n+1; i++) st.insert(i);
    set <ll> st1;
    for(int i = 0; i < n-1; i++) st1.insert(v[i]);
    st.erase(v[n-1]);
    ll ans = n * v[n-1] + *st.begin();
    for(int i = 0; i < n-1; i++){
        if(st1.size() && st.find(*st1.begin()) != st.end()){
            st.erase(*st1.begin());
            st1.erase(st1.begin());
        }
        ans += *st.begin();
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