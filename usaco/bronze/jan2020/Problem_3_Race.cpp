/*
 * Author: vss_1307
 * Created: 2026-08-26 22:55:04
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// t1 - accelerating time => t1 * (t1 + 1) / 2
// t3 - decelerating time = t1 - x => (t1 - x + 1) (x + t1) / 2
// (t1-1) t1 - x (x-1) + t1 (t1 + 1) > 2 * k
// 2 * t1 * t1 > 2 * k + x (x - 1)


// s = t1 ^ 2 / 2 + t1 * t2 + (t1 - x) ^ 2 / 2
// 2 * k < t1 ^ 2 + t1 * t2 * 2 + (t1 - x) ^ 2

// 1 + 2 + 3 + 2 + 

void solve(){ 
    int n, k; cin >> k >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        ll s = x * (x - 1) / 2;
        if (k <= s) {
            cout << ceil((-1.0 + sqrt(1.0 + 8.0 * k)) / 2.0) << nl; continue;
        } 

        ll v = sqrt(k + s); 
        if (v * v - s >= k) cout << 2 * v - x << nl;
        else if (v * v + v - s >= k) cout << 2 * v + 1 - x << nl;      
        else cout << 2 * v + 2 - x << nl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    // #ifdef ONLINE_JUDGE
        freopen("race.in", "r", stdin);
        freopen("race.out", "w", stdout);
    // #endif
    // int te; cin >> te;
    // while (te--)
        solve();
}