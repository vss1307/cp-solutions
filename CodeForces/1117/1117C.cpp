/*
 * Author: vss_1307
 * Created: 2025-12-09 22:16:08
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll n; cin >> n;
    string s; cin >> s;
    vector <pair <ll, ll> > pref(n+1);
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i];
        if(s[i] == 'U') pref[i+1].second += 1;
        if(s[i] == 'D') pref[i+1].second -= 1;
        if(s[i] == 'L') pref[i+1].first -= 1;
        if(s[i] == 'R') pref[i+1].first += 1;
    }
    ll l = -1, r = LLONG_MAX/2 - 1;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        ll cx = x1, cy = y1;
        cx += (mid/n) * pref[n].first + pref[mid%n].first;
        cy += (mid/n) * pref[n].second + pref[mid%n].second;
        if(abs(cx - x2) + abs(cy - y2) <= mid) r = mid;
        else l = mid;

    }
    if(r == LLONG_MAX/2 - 1) cout << -1 << nl;
    else cout << r << nl;
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