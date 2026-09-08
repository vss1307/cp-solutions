/*
 * Author: vss_1307
 * Created: 2025-12-17 20:20:43
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
    set <ll> st;
    for(int i = 0; i <= k; i++) st.insert(i);
    ll ans = INT_MAX;
    set <ll> tmp = st;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(x == k){
            ans = min(ans, (ll)tmp.size());
            tmp = st;
        }
        else if(x < k && tmp.find(x) != tmp.end()){
            tmp.erase(x);
        }
    }
    ans = min(ans, (ll)tmp.size());
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