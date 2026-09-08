/*
 * Author: vss_1307
 * Created: 2026-02-27 21:08:27
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
    stack <char> st;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(st.size() && st.top() == c) st.pop();
        else st.push(c);
    }
    if(st.size()) cout << "NO" << nl;
    else cout << "YES" << nl;
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