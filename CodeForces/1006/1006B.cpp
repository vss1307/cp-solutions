/*
 * Author: vss_1307
 * Created: 2026-08-17 16:34:21
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    int n ,k; cin >> n >> k;
    vector <pair <int, int> > v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v[i] = {x, i};
    }
    sort(v.rbegin(), v.rend());
    vector <int> ans;
    int sum = 0;
    for(int i = 0; i < k; i++){
        ans.push_back(v[i].second);
        sum += v[i].first;
    }
    cout << sum << nl;
    if(k == 1){
        cout << n << nl; return;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(i == 0) cout << ans[i] + 1 << ' ';
        else if(i == ans.size() - 1) cout << n - ans[i-1] - 1 << nl;
        else cout << ans[i] - ans[i-1] << ' ';
    }
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