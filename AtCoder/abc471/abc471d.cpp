/*
 * Author: vss_1307
 * Created: 2026-08-15 17:50:19
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll q, v; cin >> q >> v;
    priority_queue <array<ll,2>> pq;
    while(q--){
        ll t, time, cap;
        cin >> t;
        switch(t){
            case 1: 
                cin >> time >> cap;
                pq.push({cap - time, time});
                break;
            case 2:
                cin >> time;
                if(pq.empty()){
                    cout << -1 << nl; continue;
                }
                cout << min(v, pq.top()[0] + time) << nl;
                pq.pop();
                break;
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