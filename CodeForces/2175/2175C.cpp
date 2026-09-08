/*
 * Author: vss_1307
 * Created: 2025-12-06 14:46:16
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
    string t; cin >> t;
    vector <int> freqS(26, 0), freqT(26, 0);
    for(auto c : s){
        freqS[c - 'a']++;
    }
    for(auto c : t){
        freqT[c - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(freqS[i] > freqT[i]){
            cout << "Impossible" << nl;
            return;
        }
        freqT[i] -= freqS[i];
    }
    ll j = 0;
    for(int i = 0; i < 26; i++){
        while(freqT[i]--){
            while(j < s.size() && s[j] <= (i + 'a')){
                cout << s[j++];
            }
            cout << (char)(i + 'a');
        }
    }
    while(j < s.size()){
        cout << s[j++];
    }
    cout << nl;
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