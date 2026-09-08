/*
 * Author: vss_1307
 * Created: 2026-03-29 20:10:00
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
    vector <ll > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    set <pair<ll, ll> > st;
    ll ans = 0;
    ll best = 0;
    for(int i = 0; i < n; i++){
        while(st.size() && i+1 >= st.begin()->first){
            st.erase(st.begin());
            ans--;
        }
        ans++;
        best = max(ans, best);
        if(v[i] > i+1) st.insert({v[i], i});
    }
    cout << best << nl;
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