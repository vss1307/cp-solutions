/*
 * Author: vss_1307
 * Created: 2026-03-01 14:12:10
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
    map <ll ,ll> v;
    for(int i =0 ; i < n; i++){
        ll x; cin >> x;
        v[x]++;
    }
    set <pair <ll, ll> > o, e;
    for(auto &[x,y] : v){
        if(y&1) o.insert({y,-x});
        else e.insert({y,-x});
    }
    ll t = 0;
    ll a = 0, b = 0;
    while(o.size() || e.size()){
        if(t){
            if(o.size()){
                auto [y,x] = *o.begin();
                o.erase(o.begin());
                x = -x;
                y--;
                if(y) e.insert({y,-x});
                else a += x;
            }
            else{
                auto [y,x] = *(--e.end());
                e.erase(--e.end());
                x = -x;
                y--;
                o.insert({y,-x});
            }
        }
        else{
            if(o.size()){
                auto [y,x] = *o.begin();
                o.erase(o.begin());
                x = -x;
                y--;
                if(y) e.insert({y,-x});
                else a += x;
            }
            else{
                auto [y,x] = *(--e.end());
                e.erase(--e.end());
                o.insert({y-1,x});
            }
        }
        t ^= 1;
        for(auto &[x,y] : o) cout << x << ' ' << y << nl;
        cout << nl;
        for(auto &[x,y] : e) cout << x << ' ' << y << nl;
        cout << nl;
        
    }
    cout << a << ' ' << b << nl;
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