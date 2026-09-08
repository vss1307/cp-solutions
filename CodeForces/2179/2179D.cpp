/*
 * Author: vss_1307
 * Created: 2025-12-24 16:59:31
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
    for(int i = 0; i < (1ll<<n); i++) st.insert(i);
    ll p = n;
    ll  x = 0;
    for(int j = (1ll<<n) - 1; j>0; j/=2){
        cout << j << ' ';
        st.erase(j);
        for(int i = 0; i < (1ll << n); i++){
            if(st.find(i) == st.end()) continue;
            if( __builtin_popcount(i&j) == p ){
                cout << i << ' ';
                st.erase(i);
            }
        }
        p--;
    }
    for(auto &x : st) cout << x << ' '; cout << nl;
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