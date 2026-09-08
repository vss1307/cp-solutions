/*
 * Author: vss_1307
 * Created: 2025-12-07 21:11:47
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, m, q; cin >> n >> m >> q;
    vector <int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    ll e = 0, o = 0;
    vector <ll> c;
    ll tot = 0;
    for(int i = 0; i < n; i++){
        if(i&1) o += b[i], tot -= a[i];
        else e += b[i], tot += a[i];
    }
    c.push_back(e - o);
    ll tog = 1;
    for(int i = n; i < m; i++){
        if((i-n)&1) o -= b[i-n];
        else e -= b[i-n];
        if(i&1) o += b[i];
        else e += b[i];
        c.push_back(tog * (o - e));
        if(tog < 0) tog += 2;
        else tog -= 2;
    }
    sort(c.begin(), c.end());
    auto it = upper_bound(c.begin(), c.end(), tot);
    if(it == c.begin()) cout << *it - tot << nl;
    else if(it == c.end()) cout << tot - *(it-1) << nl;
    else cout << min(*it - tot, tot - *(it-1)) << nl;
    while(q--){
        ll l, r, x; cin >> l >> r >> x;
        l--, r--;
        if((r-l+1)%2 == 1){
            if(l&1) tot -= x;
            else tot += x;
        }
        auto it = upper_bound(c.begin(), c.end(), tot);
        if(it == c.begin()) cout << *it - tot << nl;
        else if(it == c.end()) cout << tot - *(it-1) << nl;
        else cout << min(*it - tot, tot - *(it-1)) << nl;
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
