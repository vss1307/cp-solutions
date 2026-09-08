/*
 * Author: vss_1307
 * Created: 2026-02-08 14:52:07
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, k; cin >> n >> k;
    vector <vector <ll> > v(n, vector <ll> (26));
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            v[j][c-'a']++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(n%i) continue;
        string temp = "";
        vector <vector <ll> > e(i, vector <ll> (26));
        for(int j = 0; j < n; j++){
            for(int l = 0; l < 26; l++){
                if(v[j][l]) e[j%i][l]++;
            }
        }
        for(int j = 0; j < i; j++){
            for(int l = 0; l < 26; l++){
                if(e[j][l] == n/i){
                    temp += 'a' + l;
                    break;
                }
            }
        }
        if(temp.size() != i) continue;
        for(int j = 0; j < n; j++){
            cout << temp[j%i];
        }   
        cout << nl;
        return;
    }
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