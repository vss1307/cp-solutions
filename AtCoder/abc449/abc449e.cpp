/*
 * Author: vss_1307
 * Created: 2026-03-14 18:13:46
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds; 
using namespace std;
template<typename T>
using indexed_set =  tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n, m; cin >> n >> m;
    vector <pair <ll, ll> > a(m);
    for(ll i = 0; i < m; i++){
        a[i] = {i+1, 0};
    }
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 0; i < n; i++){
        a[v[i]-1].second++;
    }
    sort(a.begin(), a.end(), [](const auto &a, const auto &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    vector <int> k(m);
    for(int i = 0; i < m-1; i++){
        ll d = a[i+1].second - a[i].second;
        k[i+1] = k[i] + (d) * (i+1);
    }
    ll q; cin >> q;
    vector < array <ll, 3> > queries;
    vector <ll> ans(q);
    for(int i = 0; i < q; i++){
        ll x; cin >> x;
        x--;
        if(x < n){
            ans[i] = v[x];
            continue;
        }
        if(x >= a.back().second * m){
            x -= a.back().second * m;
            x %= m;
            ans[i] = x+1;
            continue;
        }
        x-=n;
        ll j = upper_bound(k.begin(), k.end(), x) - k.begin() - 1;
        x -= k[j];
        x %= j+1;
        array <ll, 3> arr = {j, x, i};
        queries.push_back(arr);
    }
    sort(queries.begin(), queries.end());
    int curr = 0;
    indexed_set<ll> st;
    for(auto &[j,x,i] : queries){
        while(curr <= j) st.insert(a[curr++].first);
        ans[i] = *st.find_by_order(x);
    }
    for(auto &x : ans) cout << x << nl;
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