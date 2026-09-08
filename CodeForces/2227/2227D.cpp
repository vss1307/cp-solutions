/*
 * Author: vss_1307
 * Created: 2026-05-03 17:28:27
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    ll n; cin >> n;
    vector <ll> a(2 * n);
    for(auto &x : a) cin >> x;
    auto pal = [&](ll i, ll j) -> bool{
        while(i < j){
            if(a[i] == a[j]) i++, j--;
            else break;
        }
        return i >= j;
    };
    ll i = 0, j = 0;
    while(a[i]) i++;
    j = i+1;
    while(a[j]) j++;
    ll f = i, l = j;
    ll ans = 1;
    if(pal(i, j)){
        while(j < 2 * n && i > -1 && a[i] == a[j]) i--, j++;
        set <ll> st;
        for(int i = 0; i < n+1; i++) st.insert(i);
        while((++i) < j){
            if(st.find(a[i]) != st.end()) st.erase(a[i]);
        }
        ans = max(ans, *st.begin());
    }
    i = f, j = f;
    while(j < 2 * n && i > -1 && a[i] == a[j]) i--, j++;
    set <ll> st;
    for(int i = 0; i < n+1; i++) st.insert(i);
    while((++i) < j){
        if(st.find(a[i]) != st.end()) st.erase(a[i]);
    }
    ans = max(ans, *st.begin());
    i = l, j = l;
    while(j < 2 * n && i > -1 && a[i] == a[j]) i--, j++;
    st.clear();
    for(int i = 0; i < n+1; i++) st.insert(i);
    while((++i) < j){
        if(st.find(a[i]) != st.end()) st.erase(a[i]);
    }
    ans = max(ans, *st.begin());
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