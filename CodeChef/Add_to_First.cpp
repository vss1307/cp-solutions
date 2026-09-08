/*
 * Author: vss_1307
 * Created: 2026-01-28 20:04:43
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
    vector <ll> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    ll last = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            last = max(last, b[i]);
        }
        else if(a[i] < b[i] && last < a[i]){
            last = max(a[i], last);
        }
        else{
            cout << "No" << nl; return;
        }
    }
    cout << "Yes" << nl;
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