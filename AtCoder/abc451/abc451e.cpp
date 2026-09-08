/*
 * Author: vss_1307
 * Created: 2026-03-29 09:57:46
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <vector <array<ll, 2> > > tree;
vector <ll> depth;
vector <vector <ll> > ac;

void dfs(ll i, ll p){
    for(auto &[child, weight]: tree[i]){
        if(child == p) continue;
        depth[child]  = depth[i] + 1;
        ac[child][0] = i;
        if(ac[child][0] == -1) ac[child][0] = 0;
        for(int j = 1; j <= 20; j++){
            ac[child][j] = ac[ac[child][j-1]][j-1];
        }
        dfs(child, i);
    }
}

ll lca(ll a, ll b){
    if(depth[a] < depth[b]) swap(a, b);
    ll na = a, nb = b;
    ll d = depth[a] - depth[b];
    int j = 20;
    while(j--){
        if(d&(1ll<<j)){
            na = ac[na][j];
        }
    }
    if(na == b){
        return b;
    }
    for(j = 20; j >= 0; j--){
        if(ac[na][j] != ac[nb][j]){
            na = ac[na][j];
            nb = ac[nb][j];
        }
    }
    return ac[na][0];
}

void solve(){ 
    int n; cin >> n;
    depth = vector <ll> (n);
    ac = vector <vector <ll> > (n, vector<ll>(21));
    vector <vector <pair <ll,ll> > > v(n);
    vector <vector <ll>> a(n);
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            ll x; cin >> x;
            v[i].push_back({x, i+j+1});
            a[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }
    tree.resize(n);
    vector <ll> vis(n);
    tree[0].push_back({v[0][0].second, v[0][0].first});
    vis[0] = 1;
    vis[v[0][0].second] = 1;
    auto dfs1 = [&](ll curr, auto &self)->void{
        if(tree[curr].size() == 0) return;
        for(auto &[x, j] : v[curr]){
            for(auto &[i, q] : tree[curr]){
                if(i == j) break;
                pair<ll,ll> y;
                if(j-i > 0) y = {i, j-i-1};
                else y = {j, i-j-1};
                if(a[curr][j-curr-1] == a[curr][i-curr-1] + a[y.first][y.second]){
                    tree[i].push_back({j, a[y.first][y.second]});
                    vis[j] = 1;
                    break;
                }
            }
        }
        for(auto &[i,q] : tree[curr]) self(i, self);
    };
    dfs1(0, dfs1);
    for(auto &x : vis){
        if(x == 0){
            cout << "No" << nl; return;
        }
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll a1 = lca(i, j);
            ll dis = 0;
            if(a1 < i) dis += a[a1][i-a1-1];
            else if(a1 > i) dis += a[i][a1-i-1];
            if(a1 < j) dis += a[a1][j-a1-1];
            else if(a1 > j) dis += a[j][a1-j-1];
            if(dis != a[i][j-i-1]){
                cout << "No" << nl; return;
            }
        }
    }
    cout << "Yes" << nl;
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