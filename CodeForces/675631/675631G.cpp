/*
 * Author: vss_1307
 * Created: 2026-03-01 15:43:48
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll q = 0;
ll query(ll g){
    q++;
    cout << g << endl;
    ll res; cin >> res;
    return res;
}

void solve(){ 
    q = 0;
    ll n; cin >> n;
    ll rem = n-1;
    ll fg = n;
    if((n-1)&1) fg = n-1, rem = n;
    ll res = query(fg);
    while(res && fg > 2){
        fg--;
        res = query(fg);
    }
    if(!res) return;
    rem += q;
    fg = rem;
    res = query(fg);
    while(res && fg > 2){
        fg--;
        res = query(fg);
    }
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    int te; cin >> te;
    while (te--)
        solve();
}