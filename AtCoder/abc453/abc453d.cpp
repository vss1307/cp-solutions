/*
 * Author: vss_1307
 * Created: 2026-04-15 10:33:29
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
ll m;
vector <string> g;
vector <vector <vector <bool> > > v;
vector <char> s = {'U', 'D', 'R', 'L'};
vector <pair <ll,ll> > dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
vector <char> ans;
bool found = false;

void dfs(ll i, ll j, ll pi, ll pj){
    if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#') return;
    if(v[i][j][0] && v[i][j][1] && v[i][j][2] && v[i][j][3]) return;
    // cerr << i << ' ' << j << nl;
    if(g[i][j] == 'G'){
        found = true;
        return;
    }
    pair <ll, ll> k = {i - pi, j - pj};
    for(int d = 0; d < 4; d++){
        if(v[i][j][d]) continue;
        if(dir[d] == k && g[i][j] != 'x'){
            v[i][j][d] = true;
            dfs(i + dir[d].first, j + dir[d].second, i , j);
        }
        else if(dir[d] != k && g[i][j] != 'o'){
            v[i][j][d] = true;
            dfs(i + dir[d].first, j + dir[d].second, i , j);
        }
        if(found){
            // cout << i << ' ' << j << ' ' << s[d] << nl;
            ans.push_back(s[d]);
            return;
        }
    }
}

void solve(){ 
    cin >> n >> m;
    g.resize(n);
    v.resize(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    for(auto &x : g) cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'S'){
                dfs(i, j, -1, -1);
                if(found){
                    cout << "Yes" << nl;
                    reverse(ans.begin(), ans.end());
                    for(auto &x : ans) cout << x;
                    cout << nl;
                }
                else{
                    cout << "No" << nl;
                }
                return;
            }
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