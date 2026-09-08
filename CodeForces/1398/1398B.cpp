/*
 * Author: vss_1307
 * Created: 2026-09-04 14:00:54
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
    int n = s.size();
    vector<int> v;
    int j = 0;
    for(int i = 0; i < n;){
        while(i < n && s[i] == s[j]) i++;
        if(s[j] == '1') v.push_back(i-j);
        j = i;
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < v.size(); i+=2) ans += v[i];
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