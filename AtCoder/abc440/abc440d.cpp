/*
 * Author: vss_1307
 * Created: 2026-01-10 18:12:24
 */
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds; 
template<typename T>
using indexed_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, q; cin >> n >> q;
    indexed_set <ll> st;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        st.insert(x);
    }
    while(q--){
        ll x, y; cin >> x >> y;
        ll les = st.order_of_key(x-1);
        ll l = x-1, r = x + n + y + 5;
        while(r - l > 1){
            ll mid = (r + l) >> 1;
            ll pos = mid - (x-1);
            ll dif = st.order_of_key(mid+1) - les;
            // cout << mid << ' ' << pos 
            if(pos - dif >= y) r = mid;
            else l = mid;
        }
        cout << r << nl;
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