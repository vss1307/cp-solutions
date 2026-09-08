/*
 * Author: vss_1307
 * Created: 2025-12-07 22:16:32
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int query(int num, int sym){
    cout << "? ";
    for(int i = 0; i < num; i++) cout << sym;
    for(int i = num; i < n; i++) cout << (sym^1);
    cout << endl;
    int x; cin >> x;
    return x;
}

void solve(){ 
    cin >> n;
    int sym = 1;
    int ini = query(0, sym);
    int temp = query(1, sym);
    if(temp < ini) sym = 0, ini = n - ini;
    int l = 0, r = n;
    while(r - l > 1){
        int mid = (l + r) >> 1;
        int curr = query(mid+1, sym);
        if(curr-ini == mid+1) l = mid;
        else r = mid;
    }
    if(sym == 0) cout << "! " << r+1 << ' ' << 1 << endl;
    else cout << "! " << 1 << ' ' << r+1 << endl;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    // int te; cin >> te;
    // while (te--)
        solve();
}