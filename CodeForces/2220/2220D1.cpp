/*
 * Author: vss_1307
 * Created: 2026-04-13 21:44:46
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
    ll cmpl = query();
    // find one of the terms
    ll l = -1, r = n;
    while(r - l > 1){
        ll mid = (r + l) >> 1;
        s.erase(mid);
        ll now = query();
        if(now == cmpl){
            l = mid;
            break;
        }
        ll left = query();
        ll right = query();
        if(left == right){
            if((mid + 1 - left) % 2 == 0) right++;
            else left++;
        }
        if(left > right) r = mid;
        else l = mid;
    }
    // l = one of the terms
    
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