/*
 * Author: vss_1307
 * Created: 2026-08-26 22:29:42
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
    string s; cin >> s;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    // GHGH
    // either the first G or the first H should be the leader (can be both)
    // if G comes first, then the first H should be the leader,
        // if second H is the leader, then it should contain G leader, which should contain all the Gs, but the first G was before the first H, so not possible
    // in other if x comes first, then first y is the leader
    // and anything that can contain anything till the last x, or y can be the leader
    char x = 'G', y = 'H';
    if(s[0] == 'H') swap(x, y);
    ll lastx = -1;
    ll firsty = -1;
    ll lasty = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == x) lastx = i+1;
        if(s[i] == y) lasty = i+1;
        if(s[i] == y && firsty == -1) firsty = i+1;
    }
    if(v[firsty-1] < lasty){
        cout << 0 << nl; return;
    }
    ll ans = 0;
    for(int i = 1; i < firsty - 1; i++) if(v[i] >= firsty) ans++;
    if(v[0] >= min(firsty, lastx)) ans++;
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