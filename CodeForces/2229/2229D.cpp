/*
 * Author: vss_1307
 * Created: 2026-05-23 21:08:27
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void mergesort(vector <pair <ll, ll> > &arr, ll l, ll r, ll mid){

}

void merge(vector <pair <ll, ll> > &arr, ll l, ll r){
    if(arr.size() == 1) return;
    merge(arr, l, (l+r)/2);
    merge(arr, (l+r)/2 + 1, r);
    mergesort(arr, l, r, (l+r)/2);
}

void solve(){ 
   
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