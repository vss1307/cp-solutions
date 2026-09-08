/*
 * Author: vss_1307
 * Created: 2026-02-08 15:31:31
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
    vector <vector <ll> > v(n, vector<ll>(m));
    for(auto &x : v){
        for(auto &y : x) cin >> y;
    }
    vector <vector <ll> > d(n, vector <ll>(m)), r(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = m-2; j >= 0; j--){
            r[i][j] += r[i][j+1] + v[i][j+1];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = n-2; j >= 0; j--){
            d[j][i] += d[j+1][i] + v[j+1][i];
        }
    }
    ll x = 0, y = 0;
    string s = "";
    ll i = 0, j = 0;
    while(i < n && j < m){
        if(x + r[i][j] < y + d[i][j]){
            x += r[i][j] + v[i][j];
            s += 'D';
            i++;
        }
        else{
            y += d[i][j] + v[i][j];
            s += 'R';
            j++;
        }
    }
    cout << x * y << nl;
    while(i < n){
        s += 'D';
        i++;
    }
    while(j < m){
        s += 'R';
        j++;
    }
    cout << s << nl;
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