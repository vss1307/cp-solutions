/*
 * Author: vss_1307
 * Created: 2026-05-23 20:29:14
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
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    ll s = accumulate(v.begin(), v.end(), 0ll);
    pair <ll ,ll> mx = {s, -1};
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > 0){
            if(sum + (s - 2 * v[i]) > mx.first) mx = {sum + s - 2 * v[i], i};
            
        }
        sum += abs(v[i]), s-=v[i];
    }
    if(mx.second == -1){
        cout << 0 << nl;
        cout << nl;
        return;
    }
    ll j = mx.second-1;
    while(j >= 0 && v[j] < 0) j--;
    if(j < 0){
        cout << 1 << nl;
        cout << mx.second+1 << nl;
        return;
    }
    vector <ll> ans;
    ans.push_back(j);
    int tog = 1;
    for(int i = j-1; i >= 0; i--){
        if((v[i] > 0 && !tog) || (v[i] < 0 && tog)){
            ans.push_back(i);
            tog ^= 1;
        }
    }
    ans.push_back(mx.second);
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x+1 << ' ';
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