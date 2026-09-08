/*
 * Author: vss_1307
 * Created: 2026-08-22 17:34:34
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> v(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i >= m) sum -= v[i-m];
        if(sum + v[i] <= k){
            sum += v[i];
            cout << "Yes" << nl;
        }
        else{
            v[i] = 0;
            cout << "No" << nl;
        }
    }

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