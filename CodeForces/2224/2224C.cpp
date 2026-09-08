/*
 * Author: vss_1307
 * Created: 2026-05-06 11:45:47
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n; cin >> n;
    string s,t; cin >> s >> t;
    ll os = 0, ot = 0;
    vector <array <ll, 5> > d;
    ll ms = INT_MAX, mt = ms;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' && t[i] == s[i]) os++, ot++;
        else if(s[i] == ')' && t[i] == s[i]) os--, ot--;
        else {
            d.push_back({i, os, ot, ms, mt});
            ms = os, mt = ot;
        }
        ms = min(ms, os);
        mt = min(mt, ot);
    }
    d.push_back({n, os, ot, ms, mt});
    if(d[0][3] < 0 || d[0][4] < 0){
        cout << "NO" << nl; return;
    }
    ll x = 0, y = 0;
    for(int i = 0; i < d.size() - 1; i++){
        if(os + x < ot + y && d[i][2] + y > 0 && d[i+1][4] + y > 0) x++, y--;
        else if(os + x > ot + y && d[i][1] + x > 0 && d[i+1][3] + x > 0) x--, y++;
        else{
            if(d[i][2] + y > 0 && d[i+1][4] + y > 0) x++, y--;
            else if(d[i][1] + x > 0 && d[i+1][3] + x > 0) x--, y++;
            else{
                cout << "NO" << nl; return;
            }
        }
    }
    if(os == 0 && ot == 0) cout << "YES" << nl;
    else cout << "NO" << nl;
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