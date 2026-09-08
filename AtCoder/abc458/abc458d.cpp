/*
 * Author: vss_1307
 * Created: 2026-05-16 17:40:20
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
template<typename T>
using indexed_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll x, q; cin >> x >> q;
    indexed_set < pair <ll, ll> > st;
    st.insert({x, 0});
    while(q--){
        ll a, b; cin >> a >> b;
        st.insert({a, MAXN + q+1});
        st.insert({b, q+1});
        cout << st.find_by_order(st.size()/2)->first << nl;
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