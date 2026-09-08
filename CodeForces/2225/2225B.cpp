/*
 * Author: vss_1307
 * Created: 2026-04-21 20:09:47
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string s; cin >> s;
    ll i = 0, j = 0;
    ll k = 0;
    for(; k < s.size()-1; k++){
        if(s[k] == s[k+1]){
            if(i){
                cout << "NO" << nl; return;
            }
            i = k+1;
            k++;
            while(k < s.size() - 1 && s[k] != s[k+1]) k++;
            j = k;
        }
    }
    cout << "YES" << nl;
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