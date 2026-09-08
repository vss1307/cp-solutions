/*
 * Author: vss_1307
 * Created: 2026-01-20 18:46:57
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
    vector <pair <ll ,ll> > v(n);
    for(auto &[x,y] : v) cin >> x >> y;
    sort(v.begin(), v.end());
    vector <int> ans(n);
    int curr = 0;
    multiset <ll> st;
    ll l = v[0].first;
    for(int i = 0; i < n; i++){
        while(st.size() && *st.begin() < v[i].first){
            curr--;
            ans[curr] += *st.begin() - l + 1;
            l = *st.begin() + 1;
            st.erase(st.begin());
        }
        if(curr) ans[curr-1] += v[i].first - l;
        l = v[i].first;
        curr++;
        st.insert(v[i].second);
    }
    while(st.size()){
        curr--;
        ans[curr] += *st.begin() - l + 1;
        l = *st.begin() + 1;
        st.erase(st.begin());
    }
    for(auto &x : ans) cout << x << ' ' ; cout << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    int te = 1; 
    // cin >> te;
    while (te--)
        solve();
}