/*
 * Author: vss_1307
 * Created: 2026-05-16 20:22:52
 */
#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll a, n; cin >> a >> n;
    ll ans = ULLONG_MAX;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    auto func = [](ll x, ll d, ll sz) -> ll{
        ll res = 0;
        while(sz--) res = (res * 10) + d, x *= 10;
        return res + x;
    };
    string s = to_string(a);
    ll sz = s.size();
    if (sz > 1) ans = min(ans, a - func(0, v.back(), sz-1)); 

    if (n > 1 && v[0] == 0)  ans = min(ans, func(v[1], v[0], sz) - a);
    else if (v[0] != 0) ans = min(ans, func(v[0], v[0], sz) - a);
    else  ans = min(ans, a); 
    
    ll curr = 0;
    for(int len = 0; len < sz; len++){
        curr *= 10;
        ll x = -1;
        ll y = 100;
        ll z = -1;
        for(int i = 0; i < n; i++){
            if(v[i] < s[len] - '0') x = v[i];
            if(v[i] > s[len] - '0') y = min(y, v[i]);
            if(v[i] == s[len] - '0') z = v[i];
        }
        if(x != -1) ans = min(ans, a - func(curr + x, v.back(), sz-1-len));
        if(y != 100) ans = min(ans, func(curr + y, v[0], sz-1-len) - a);
        if(z == -1) break;
        else curr += z;

        if(len == sz - 1) ans = min(ans, (a > curr ? a - curr : curr - a));
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