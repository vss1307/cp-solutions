/*
 * Author: vss_1307
 * Created: 2026-02-27 21:26:44
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> spf(MAXN);
vector <ll> primes;

void seive(){
    for(int i = 0; i < MAXN; i++) spf[i] = i;
    for(int i = 2; i < MAXN; i++){
        if(spf[i] == i){
            primes.push_back(i);
        }
        for(auto &x : primes){
            if(x * i >= MAXN) break;
            spf[i * x] = x;
            if(i % x == 0) break;
        }
    }
}

void solve(){ 
    ll n; cin >> n;
    vector <ll> v(n);
    for(auto &x : v) cin >> x;
    bool check = true;
    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]) check = false;
    }
    if(check){
        cout << "Bob" << nl; return;
    }
    vector <ll> ans;
    for(int i = 0; i < n; i++){
        ll x = v[i];
        while(spf[x] != x){
            x/=spf[x];
        }
        ans.push_back(x);
        ans.push_back(spf[v[i]]);
        // cout << x << ' ' << spf[v[i]] << nl;
        if(x > spf[v[i]]){
            cout << "Alice" << nl; return;
        }
    }
    for(int i = 0; i < ans.size() - 1; i++){
        if(ans[i] > ans[i+1]){
            cout << "Alice" << nl;
            return;
        }
    }
    cout << "Bob" << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    seive();
    int te; cin >> te;
    while (te--)
        solve();
}