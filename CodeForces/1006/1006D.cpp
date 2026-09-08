/*
 * Author: vss_1307
 * Created: 2026-08-17 16:55:21
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < n/2; i++){
        map <char, ll> mp;
        mp[a[i]]++;
        mp[a[n-i-1]]++;
        mp[b[i]]++;
        mp[b[n-i-1]]++;
        if(mp.size() == 4) ans += 2;
        else if(mp.size() == 3){
            if(a[i] == a[n-i-1]) ans+=2;
            else ans++;
        }
        else{
            if(mp[a[i]]%2) ans++;
        }
        // cout << ans << nl;
    }
    if(n%2) ans += (a[n/2] != b[n/2]);
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