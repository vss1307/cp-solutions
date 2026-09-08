/*
 * Author: vss_1307
 * Created: 2026-03-07 17:35:10
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, q; cin >> n >> q;
    set <pair <ll, ll> > st;
    vector <ll> v(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        st.insert({x, i});
        v[i] = x;
    }
    set <pair <ll ,ll> > rem;
    while(q--){
        ll k; cin >> k;
        for(int i = 0; i < k; i++){
            ll x; cin >> x;
            x--;
            st.erase({v[x], x});
            rem.insert({v[x], x});
        }
        cout << st.begin()->first << nl;
        for(int i = 0; i < k; i++){
            st.insert(*rem.begin());
            rem.erase(rem.begin());
        }
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