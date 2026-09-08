/*
 * Author: vss_1307
 * Created: 2026-08-15 17:36:10
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    set <ll> st;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        st.insert(x);
    }
    ll curr = 0;
    ll ans = 0;
    while(st.size()){
        auto it = st.upper_bound(curr);
        auto it2 = it;
        ll x = LLONG_MAX/2;
        ll y = LLONG_MIN/2;
        if(it != st.end()) x = *it;
        if(it != st.begin()) y = *(--it2);
        if(abs(curr - x) < abs(curr - y)){
            ans += abs(curr - x), curr = x;
            st.erase(it);
        }
        else{
            ans += abs(curr - y), curr = y;
            st.erase(it2);
        }
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