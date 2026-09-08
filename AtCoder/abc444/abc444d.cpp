/*
 * Author: vss_1307
 * Created: 2026-02-07 17:45:20
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector <ll> v(MAXN);
    ll mx = 0;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        mx = max(x, mx);
        v[x-1]++;
    }
    for(int i = v.size() - 1; i > 0; i--) v[i-1] += v[i];
    ll sum = 0;
    string ans;
    for(int i = 0; i < v.size() && v[i]; i++){
        sum += v[i];
        ans += '0' + sum%10;
        sum /= 10;
    }
    while(sum){
        ans += '0' + sum%10;
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << nl;
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