/*
 * Author: vss_1307
 * Created: 2026-01-17 14:25:55
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
    string s; cin >> s;
    vector <ll> a, p;
    for(int i = 0; i < n; i++){
        if(s[i] == 'P') p.push_back(i);
        if(s[i] == '*') a.push_back(i);
    }
    ll l = 0, r = 1e9;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        auto check = true;
        ll curr_p = 0;
        ll curr_a = 0;
        ll pos = -1;
        while(curr_a < a.size() && curr_p < p.size()){
            if(a[curr_a] <= pos){
                curr_a++;
                continue;
            }

            ll d = p[curr_p] - a[curr_a];
            if(d > mid){
                curr_p++;
                continue;
            }
            ll nxt = 0;
            if(d > 0){
                ll rl1 = (mid - d) / 2;
                ll rl2 = (mid - 2 * d);
                nxt = max(rl1, rl2);
            }
            else{
                nxt = mid;
            }
            pos = p[curr_p++] + nxt;
        }
        if(curr_a == a.size() || a.back() <= pos) r = mid;
        else l = mid;
    }
    cout << r << nl;
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