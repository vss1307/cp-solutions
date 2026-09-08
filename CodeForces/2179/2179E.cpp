/*
 * Author: vss_1307
 * Created: 2025-12-24 17:14:43
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    if(sum > x + y){
        cout << "NO" << nl; return;
    }
    ll a = 0, b = 0;
    bool o = false, z = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') b += v[i] / 2 + 1, o = true;
        else a += v[i] / 2 + 1, z = true;
    }   
    if(a > x || b > y){
        cout << "NO" << nl; return;
    }
    if(!(o&z)){
        if((o && y < n + x) || (z && x < n + y)) {cout << "NO" << nl; return;}
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