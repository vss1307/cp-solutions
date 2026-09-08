/*
 * Author: vss_1307
 * Created: 2025-12-11 20:19:15
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
    vector <ll> o, e;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        if(x&1) o.push_back(x);
        else e.push_back(x);
    }
    sort(o.begin(), o.end());
    if(e.size() == 0){
        for(int i = 0; i < n; i++){
            if(i&1) cout << 0 << ' ';
            else cout << o.back() << ' ';
        }
        cout << nl;
        return;
    }
    if(o.size() == 0){
        for(int i = 0; i < n; i++){
            cout << 0 << ' ';
        }
        cout << nl;
        return;
    }
    sort(e.rbegin(), e.rend());
    vector <ll> pref(e.size() + 1);
    for(int i = 0; i < e.size(); i++) pref[i+1] = pref[i] + e[i];
    for(int i = 0; i <= e.size(); i++){
        cout << o.back() + pref[i] << ' ';
    }
    ll rem = n - e.size() - 1;
    for(int i = 0; i < rem; i++){
        if(!(i&1)){
            ll gap = i+1;
            if(gap+1 < o.size()) cout << o.back() + pref[e.size() - 1] << ' ';
            else cout << 0 << ' ';
        }
        else cout << o.back() + pref[e.size()] << ' ';
    }
    cout << nl;
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