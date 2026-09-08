/*
 * Author: vss_1307
 * Created: 2026-08-22 17:40:51
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<int, int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(){ 
    int n, m, k; cin >> n >> m >> k;
    vector<vector<bool>> v(n, vector<bool>(m));
    vector<int> rs(n);
    vector<int> cs(m);
    for(int i = 0; i < n; i++){
        string s ; cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                v[i][j] = true;
                cs[j] += 1;
                rs[i] += 1;
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<array<int, 3>> q;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!(rs[i]|cs[j])){
                ans++;
                vis[i][j] = true;
                if(k>=1) q.push({i, j, k});
            }
        }
    }
    while(q.size()){
        auto &[x, y, z] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + dir[i].first;
            int dy = y + dir[i].second;
            if(dx >= n || dx < 0 || dy >= m || dy < 0 || v[dx][dy] || vis[dx][dy]) continue;
            ans++;
            vis[dx][dy] = true;
            if(z>1) q.push({dx, dy, z-1});
        }
    }
    cout << ans << nl;
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