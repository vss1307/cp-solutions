/*
 * Author: vss_1307
 * Created: 2026-04-18 18:04:38
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, a, b; cin >> n >> a >> b;
    if(n%2){
        cout << "No" << nl; return;
    }
    a--,b--;
    map <pair <ll, ll> , char> mp;
    mp[{-1, 0}] = 'U';
    mp[{1, 0}] = 'D';
    mp[{0, 1}] = 'R';
    mp[{0, -1}] = 'L';
    vector <pair <ll, ll> > dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
     //                                L       U        R       D             
    ll i = 0, j = 0;
    ll rem = n*n - 2;
    vector <ll> vis(n*n);
    vis[0] = true;
    string ans;
    while(rem){
        bool can = false;
        for(auto &[x,y] : dir){
            if((i+x) >= 0 && j+y >= 0 && i+x < n && j+y < n && !vis[(i+x)*n + j+y]){
                if(i+x == a && j+y == b) continue;
                vis[(i+x)*n + j+y] = true;
                rem--;
                ans.push_back(mp[{x,y}]);
                i+=x, j+=y;
                can = true;
                break;
            }
        }
        if(!can){
            // cout << ans << nl;
            cout << "No" << nl; return;
        }
    }
    cout << "Yes" << nl;
    cout << ans << nl;
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