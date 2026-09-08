/*
 * Author: vss_1307
 * Created: 2026-02-15 20:58:47
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
    vector < vector <ll> > v(n+1);
    vector <ll> p(n+1, -1);
    v[0].push_back(1);
    p[1] = 0;
    for(int i = 1; i <= n; i++){
        ll x,y; cin >> x >> y;
        if(x){
            v[i].push_back(x);
            v[i].push_back(y);
            p[x] = i;
            p[y] = i;
        }
    }
    queue <ll> q;
    for(int i = 1; i <= n; i++) if(v[i].size() == 0) q.push(i);
    vector <ll> t(n+1, 0);
    vector <ll> pt(n+1, 0);
    while(q.size()){
        ll x = q.front(); q.pop();
        t[x] = 1;
        if(v[x].size()) t[x] += t[v[x][0]] + t[v[x][1]] + 2;
        t[x] %= MOD;
        pt[p[x]]++;
        if(pt[p[x]] == 2) q.push(p[x]);
    }
    q.push(1);
    while(q.size()){
        ll x = q.front(); q.pop();
        t[x] = (t[x] + t[p[x]]) % MOD;
        if(v[x].size()){
            q.push(v[x][0]);
            q.push(v[x][1]);
        }
    }
    for(int i = 1; i <= n; i++) cout << t[i] << ' ';
    cout << nl;
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