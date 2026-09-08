/*
 * Author: vss_1307
 * Created: 2026-05-03 18:01:58
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
    vector <ll> v(n), h(n), h3(n), h4(n);
    for(auto &x : v) cin >> x;
    vector <ll> v1(n);
    ll l = n;
    ll ans1 = 0;
    for(int i = n-1; i >= 0; i--){
        if(l < v[i]) v1[i] = l;
        else v1[i] = v[i];
        l = min(l, v[i]);
        h[v1[i]-1]++;
        h4[v[i]-1]++;
        h3[v[i]-1] += i;
        // cout << v1[i] << ' ';
    }
    for(int i = n-2; i >= 0; i--) h[i] += h[i+1], h3[i] += h3[i+1], h4[i] += h4[i+1];
    // for(auto &x : h4) cout << x << ' '; cout << nl;
    // for(auto &x : h3) cout << x << ' '; cout << nl;
    for(int i = n-1; i >= 0; i--){
        ans1 += h4[i] * n - h4[i] * (h4[i] + 1) / 2 - h3[i];
        // cout << h4[i] << ' ' << h3[i] << ' ';
        // cout << ans1 << nl;
    }
    // for(auto &x : h) cout << x << ' '; cout << nl;
    // for(auto &x : v1) cout << x << ' '; cout << nl;
    pair <ll, ll> s = {0, 0};
    for(ll i = n-1; i >= 0; i--){
        if((h4[v[i]-1]-1) * n - (h4[v[i]-1]-1) * ((h4[v[i]-1]-1) + 1) / 2 - (h3[v[i]-1]-i) - (h4[v[i]-1] * n - h4[v[i]-1] * (h4[v[i]-1] + 1) / 2 - h3[v[i]-1]) > s.first){
            s = {(h4[v[i]-1]-1) * n - (h4[v[i]-1]-1) * ((h4[v[i]-1]-1) + 1) / 2 - (h3[v[i]-1]-i) - (h4[v[i]-1] * n - h4[v[i]-1] * (h4[v[i]-1] + 1) / 2 - h3[v[i]-1]), i};
        }
    }
    // cout << s.first << ' ';
    // cout << s.second << nl;
    v1[s.second]--;
    v[s.second]--;
    vector <ll> h1(n);
    vector <ll> h2(n);
    for(int i = 0; i < n; i++){
        if(v[i] > 0){
            h1[v[i]-1] += i;
            h2[v[i]-1]++;
        }
    }
    for(int i = n-2; i >= 0; i--) h1[i] += h1[i+1];
    for(int i = n-2; i >= 0; i--) h2[i] += h2[i+1];
    // for(auto &x : h1) cout << x << ' '; cout << nl;
    // for(auto &x : h2) cout << x << ' '; cout << nl;
    ll ans = 0;
    for(int i = n-1; i>=0; i--){
        ans += h2[i] * n - h2[i] * (h2[i] + 1) / 2 - h1[i];
        // cout << h2[i] << ' ' << h1[i] << ' ';
        // cout << ans << nl;
    }
    cout << max(ans1, ans) << nl;
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