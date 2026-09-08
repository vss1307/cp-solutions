/*
 * Author: vss_1307
 * Created: 2025-12-09 23:27:42
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <vector <ll> > mul(vector <vector <ll> > a, vector <vector <ll> > b, ll mod){
    ll n = a.size();
    vector <vector <ll> > res(n, vector <ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

vector <vector <ll>> exp(vector <vector <ll>> base, ll power, ll mod){
    ll n = base.size();
    vector <vector <ll>> res(n, vector <ll> (n, 0));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    while(power){
        if(power&1) res = mul(res, base, mod);
        base = mul(base, base, mod);
        power >>= 1;
    }
    return res;
}

void solve(){ 
    ll n, m; cin >> n >> m;
    if(m > n){
        cout << 1 << nl; return;
    }
    m--;
    vector <vector <ll> > t(m+1, vector <ll> (m+1));
    t[0][0] = t[0][m] = 1;
    for(int i = 1; i <= m; i++) t[i][i-1] = 1;
    t = exp(t, n-m, MOD);
    ll ans = 0;
    for(int i = 0; i <= m; i++) ans = (ans + t[0][i]) % MOD;
    cout << ans<< nl;
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