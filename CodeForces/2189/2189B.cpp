/*
 * Author: vss_1307
 * Created: 2026-01-23 20:19:50
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, x; cin >> n >> x;
    vector <array<ll, 3>> v(n);
    for(auto &[x1,y,z] : v) cin >> x1 >> y >> z;
    sort(v.begin(), v.end(), [](const auto a, const auto b){
        return (a[0] * a[1] - a[2]) * b[1] < (b[0] * b[1] - b[2]) * a[1];
    });
    ll y = 0;
    for(int i = 0; i < n; i++){
        y += v[i][0] * (v[i][1] - 1);
    }
    bool l = false;
    if(v.back()[0] * v.back()[1] - v.back()[2] <= 0) l = true;
    if(y < x && l){
        cout << -1 << nl; return;
    }
    ll ans = 0;
    if(y < x){
        ll dis = x - y + v.back()[0] * (v.back()[1] - 1);
        ans = dis/(v.back()[0] * v.back()[1] - v.back()[2]);
        if(ans * (v.back()[0] * v.back()[1] - v.back()[2]) + (v.back()[0] * (v.back()[1] - 1)) < dis) ans++;
        ll c = (ans - 1) * (v.back()[0] * v.back()[1] - v.back()[2]);
        dis -= c;
        if(dis + (v.back()[0] * (v.back()[1] - 1)) >= x) ans--;
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