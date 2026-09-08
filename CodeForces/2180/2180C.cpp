/*
 * Author: vss_1307
 * Created: 2025-12-19 20:18:53
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    if(k%2){
        for(int i = 0; i < k; i++) cout << n << ' ';
        cout << nl;
        return;
    }
    for(int i = 0; i < k-2; i++) cout << n << ' ';
    vector <ll> v;
    ll i = 0;
    while((1ll<<i) <= n){
        v.push_back((n>>i)&1);
        i++;
    }
    ll x = (1ll<<(i-1));
    ll r = -1;
    for(i = 0; i < v.size()-1; i++) if(v[i]) r = i;
    for(int j = 0; j < r; j++) x += (1ll<<j);
    // for(int j = r+1; j < v.size(); j++) x += ((v[j])<<j);
    ll y = (n^x);
    cout << x << ' ' << y << nl;    
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