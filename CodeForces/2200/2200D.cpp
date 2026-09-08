/*
 * Author: vss_1307
 * Created: 2026-02-27 21:14:03
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n, x,y; cin >> n >> x >> y;
    vector <ll> l, c, r;
    for(int i = 0; i < n; i++){
        ll q; cin >> q;
        if(i < x) l.push_back(q);
        else if(i < y) c.push_back(q);
        else l.push_back(q);
    }
    vector <int> nc;
    auto it = min_element(c.begin(), c.end()) - c.begin();
    for(int i = 0; i < c.size(); i++){
        // auto it = (min_element(c.begin(), c.end()) - c.begin() + i) % c.size();
        nc.push_back(c[(it+i)%c.size()]);
    }
    for(int i = 0; i < l.size(); i++){
        if(l[i] < nc[0]) cout << l[i] << ' ';
        else{
            for(auto &q : nc) cout << q << ' ';
            while(i < l.size()) cout << l[i++] << ' ';
            cout << nl;
            return;
        }
    }
    for(auto &q : nc) cout << q << ' '; cout << nl;
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