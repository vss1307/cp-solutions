/*
 * Author: vss_1307
 * Created: 2025-12-10 16:31:24
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
    vector <ll> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll x = k;
    ll i = 0, j = n-1;
    ll curr = a[j] - a[i];
    while(i < j && x >= 0){
        while(i < j && a[i+1] == a[i]) i++;
        while(i < j && a[j] == a[j-1]) j--;
        if(i == j) break;
        ll dist_i = min(x/(i+1), a[i+1] - a[i]);
        ll dist_j = min(x/(n-j), a[j] - a[j-1]);
        if(dist_i == 0 && dist_j == 0) break;
        if(dist_j && n-j <= i+1){
            x -= dist_j * (n-j);
            j--;
            curr -= dist_j;
        }
        else{
            x -= dist_i * (i+1);
            i++;
            curr -= dist_i;
        }
    }
    cout << curr << nl;
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