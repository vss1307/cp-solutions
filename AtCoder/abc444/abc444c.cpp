/*
 * Author: vss_1307
 * Created: 2026-02-07 17:36:29
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    auto func = [](multiset <ll> st, ll k)->bool{
        while(st.size()){
            ll x = *st.begin();
            st.erase(st.begin());
            auto it = st.find(k - x);
            if(it == st.end()) return false;
            st.erase(it);
        }
        return true;
    };
    multiset <ll> st;
    for(int i = 0; i < n && v[i] < v[n-1]; i++){
        st.insert(v[i]);
    }
    vector <ll> ans;
    if(func(st, v[n-1])) ans.push_back(v[n-1]);
    for(int i = n-1; i >= 0 && v[i] == v[n-1]; i--) st.insert(v[i]);
    if(func(st, v[0] + v[n-1])) ans.push_back(v[0] + v[n-1]);
    for(auto &x : ans) cout << x << ' ';
    cout << nl;
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