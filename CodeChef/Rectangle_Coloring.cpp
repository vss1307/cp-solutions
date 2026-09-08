/*
 * Author: vss_1307
 * Created: 2026-01-14 20:11:25
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll l, w; cin >> l >> w;
    if(l > w) swap(l, w);
    vector <ll> f = {l, l, w, w};
    vector <ll> c(3);
    for(auto &x : c) cin >> x;
    sort(c.rbegin(), c.rend());
    ll ans = 10;
    auto tc = c, tf = f;
    do{
        do{
            ll s = 0;
            for(int i = 0; i < 4; i++){
                s++;
                if(tf[i] > tc.back()){
                    tf[i] -= tc.back();
                    tc.pop_back();
                    i--;
                }
                else tc.back() -= tf[i];
            }
            ans = min(ans, s);
            tc = c, tf = f;
        }
        while(prev_permutation(c.begin(), c.end()));
    }
    while(next_permutation(f.begin(), f.end()));

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