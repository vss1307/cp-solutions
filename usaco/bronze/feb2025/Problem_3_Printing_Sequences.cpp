/*
 * Author: vss_1307
 * Created: 2026-08-25 20:35:55
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool func(const vector<int>& v, const int& l, const int& r, const int& k){
    bool same = true;
    for(int i = l+1; i <= r; i++) if(v[l] != v[i]) same = false;
    if(same) return same;
    if(k == 1) return same;

    int n = r-l+1;
    vector<int> b;
    for(int i = l; i <= r; i++){
        b.push_back(v[i]);
        if(n % (i-l+1)) continue;
        bool check = true;
        for(int j = l; j <= r; j+=(i-l+1)){
            for(int m = j; m < j + i-l + 1; m++){
                if(b[m-j] != v[m]) check = false;
            }
        }
        if(check) break;
    }
    int n1 = b.size();
    for(int i = 0; i < n1-1; i++){
        for(int j = 1; j < k; j++){
            if(func(b, 0, i, j) && func(b, i+1, n1 - 1, k-j)) return true;
        }
    }

    return false;
}

void solve(){ 
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    cout << (func(v, 0, n-1, k) ? "YES" : "NO") << nl;
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