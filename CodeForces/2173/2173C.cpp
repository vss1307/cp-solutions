#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve(){ 
    int n, k; cin >> n >> k;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    vector <ll> ans;
    set <ll> st;
    for(auto &x :v) st.insert(x);
    map <ll, bool> done;
    for(int i = 0; i < n; i++){
        if(st.find(v[i]) != st.end()) st.erase(v[i]);
        if(done[v[i]]) continue;
        done[v[i]] = true;
        for(int j = 2; v[i] * j <= k; j++){
            if(st.find(v[i] * j) == st.end()){
                cout << -1 << nl; return;
            }
            else done[v[i] * j] = true;
        }
        ans.push_back(v[i]);
    }
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x << ' ';
        cout << nl;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("error.txt", "w", stderr);
    int te; cin >> te;
    while (te--)
        solve();
}
 