/*
 * Author: vss_1307
 * Created: 2026-04-21 20:21:09
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 998244353;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector <ll> dp;
vector <ll> v;

ll fi(ll st, ll x){
    if(st == n) return 0;
    if(dp[st] != -1) return dp[st];
    ll f = 0;
    ll l = 0;
    ll g = 0;
    ll sz = 0;
    for(ll i = st; i < n; i++){
        sz++;
        if(v[i] < x) l++;
        if(v[i] > x) g++;
        if(v[i] == x) f = 1;
        if(sz%2){
            if(l <= sz/2 && g <= sz/2 && f){
                ll k = fi(i+1, x);
                if(k != -1) dp[st] = max(dp[st], 1 + fi(i+1, x));
            }
        }
    }
    return dp[st];
}

void solve(){ 
    cin >> n;
    v = vector <ll> (n);
    for(auto &x : v) cin >> x;
    auto v1 = v;
    sort(v1.begin(), v1.end());
    set <ll> st;
    for(auto &x : v) st.insert(x);
    vector <ll> un;
    for(auto &x : st) un.push_back(x);
    ll ans = 1;
    // for(auto &x : un){
        dp = vector <ll> (n, -1);
        ans = max(ans, fi(0, v1[(n-1)/2]));
    // }
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