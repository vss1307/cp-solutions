/*
 * Author: vss_1307
 * Created: 2026-02-21 18:01:13
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll m, a, b; cin >> m >> a >> b;
    ll rem = m * m;
    queue <ll> q;
    vector <vector <ll> > v(m * m);
    vector <ll> vis(m * m);
    for(int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            ll curr = m * x + y;
            ll z = (a * x + b * y) % m;
            ll next = m * z + x;
            v[next].push_back(curr);
            if((x == 0 || y == 0)){
                vis[curr] = 1;
                q.push(curr);
            }
        }
    }

    while(q.size()){
        auto x = q.front(); q.pop();
        rem--;
        for(auto &prev : v[x]){
            if(!vis[prev]){
                vis[prev] = 1;
                q.push(prev);
            }
        }
    }
    cout << rem << nl;
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