/*
 * Author: vss_1307
 * Created: 2025-12-27 20:47:40
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector <pair <ll, ll> > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    // for(auto &x : v) cout << x.first << ' '; cout << nl;
    if(m > n/2){
        cout << -1 << nl; return;
    }
    vector <pair <ll ,ll> > op;
    if(m != 0){
        for(int i = n-1; i >= n-m; i--) op.push_back({i, i-m});
        ll j = op.back().second;
        while(j > 0){
            op.push_back({j, j-1});
            j--;
        }
        reverse(op.begin(), op.end());
        cout << op.size() << nl;
        for(int i = 0; i < op.size(); i++){
            cout << v[op[i].first].second << ' ' << v[op[i].second].second << nl;
        }
        return;
    }
    ll sum = 0;
    for(int i = 0; i < n-1; i++) sum += v[i].first;
    if(v[n-1].first > sum){
        cout << -1 << nl; return;
    }
    ll j = 0;
    while(j + 1 < n-1 && sum - v[j].first >= v[n-1].first){
        op.push_back({j, j+1});
        sum -= v[j].first;
        j++;
    }
    while(j < n-1){
        op.push_back({j,n-1});
        v[n-1].first -= v[j].first;
        j++;
    }
    cout << op.size() << nl;
    for(int i = 0; i < op.size(); i++){
        cout << v[op[i].first].second << ' ' << v[op[i].second].second << nl;
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