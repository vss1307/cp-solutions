/*
 * Author: vss_1307
 * Created: 2026-02-15 20:25:48
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
    map <ll, ll> opp;
    for(int i = 0; i < 6; i++){
        opp[i+1] = 6 - i;
    }
    set <ll> st;
    for(int j = 1; j < 7; j++) st.insert(j);
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(v[i] == v[i-1] || v[i] == opp[v[i-1]]){
            auto s = st;
            s.erase(v[i-1]);
            s.erase(opp[v[i-1]]);
            if(i+1 < n){
                if(s.find(v[i+1]) != s.end()) s.erase(v[i+1]);
                if(s.find(opp[v[i+1]]) != s.end()) s.erase(opp[v[i+1]]);
            }
            v[i] = *s.begin();
            ans++;
        }
    }
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