/*
 * Author: vss_1307
 * Created: 2026-08-18 12:19:19
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector<vector<ll>> v(n);
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue <ll> q;
    vector <ll> vis(n, -1);
    vector<ll> s1, s2;
    q.push(0);
    vis[0] = 0;
    while(q.size()){
        auto x = q.front(); q.pop();
        if(vis[x] == 0) s1.push_back(x);
        if(vis[x] == 1) s2.push_back(x);
        for(auto &child : v[x]){
            if(vis[child] == -1){
                vis[child] = 1 - vis[x];
                q.push(child);
            }
            else if(vis[child] == vis[x]){
                cout << "Alice" << endl;
                for(int i = 0; i < n; i++){
                    cout << 1 << ' ' << 2 << endl;
                    ll x, y; cin >> x >> y;
                }
                return;
            }
        }
    }
    cout << "Bob" << endl;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ll c, s;
        if(s1.empty()){
            c = (a == 1? b : a);
            s = s2.back(); s2.pop_back();
        }
        else if(s2.empty()){
            c = (a == 2? b : a);
            s = s1.back(); s1.pop_back();
        }
        else{
            if(a == 1 || b == 1){
                c = 1;
                s = s1.back(); s1.pop_back();
            }
            else{
                c = 2;
                s = s2.back(); s2.pop_back();
            }
        }
        cout << s+1 << ' ' << c << endl;
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