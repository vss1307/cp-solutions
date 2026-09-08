/*
 * Author: vss_1307
 * Created: 2026-08-12 10:46:30
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> ans;
set<int> st;

void func(){
    if(st.empty()){
        for(auto x : ans) cout << x << ' ';
        exit(0);
    }
    for(int x : st){
        if(ans.empty() || abs(ans.back() - x) != 1){
            ans.push_back(x);
            st.erase(x);
            func();
            st.insert(x);
            ans.pop_back();
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) st.insert(i+1);
    func();
    cout << "NO SOLUTION" << nl;
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