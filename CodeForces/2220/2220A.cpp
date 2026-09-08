/*
 * Author: vss_1307
 * Created: 2026-04-13 20:08:01
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
    set <int> st;
    bool ans = true;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(st.find(x) != st.end()) ans = false;
        st.insert(x);
    }
    if(ans){
        auto it = (st.end());
        while(it != st.begin()){
            it--;
            cout << *it << ' ';
        }
        cout << nl;
    }
    else cout << -1 << nl;
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