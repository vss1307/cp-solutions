/*
 * Author: vss_1307
 * Created: 2026-02-07 17:53:40
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, d; cin >> n >> d;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll ans = 0;
    set <ll> st;
    ll l = 0;
    for(int r = 0; r < n; r++){
        ll u = LLONG_MAX/2;
        ll b = LLONG_MIN/2;
        auto it = st.lower_bound(v[r]);
        if(it != st.end()) u = min(u, *it);
        if(it != st.begin()){
            it--;
            b = max(b, *it);
        }
        // cout << u << ' ' << b << nl;
        while(l <= r && (u - v[r] < d || v[r] - b < d)){
            // cout << l << ' ';
            st.erase(st.find(v[l]));
            l++;
            u = LLONG_MAX/2;
            b = LLONG_MIN/2;
            it = st.lower_bound(v[r]);
            if(it != st.end()) u = min(u, *it);
            if(it != st.begin()){
                it--;
                b = max(b, *it);
            }
        }
        st.insert(v[r]);
        ans += r - l + 1;
        // cout << ans << nl;
    }
    cout << ans << nl;
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