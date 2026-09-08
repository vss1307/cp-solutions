/*
 * Author: vss_1307
 * Created: 2026-02-15 20:19:54
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
    vector <ll> ans(n, -1);
    for(int i = 0; i < n; i++){
        if(ans[i] != -1) continue;
        vector <ll> k;
        for(int j = i+1; j <= n; j *= 2){
            k.push_back(v[j-1]);
        }
        sort(k.begin(), k.end());
        ll x = 0;
        for(int j = i+1; j <= n; j *= 2){
            ans[j-1] = k[x++];
        }
    }
    auto temp = ans;
    sort(temp.begin(), temp.end());
    for(int i =0 ; i < n; i++){
        if(temp[i] != ans[i]){
            cout << "NO" << nl; return;
        }
    }
    cout << "YES" << nl;
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