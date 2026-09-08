/*
 * Author: vss_1307
 * Created: 2026-08-22 10:41:46
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
class FenwickTree{
  public:
    int n;
    vector<T> ws;
    vector<T> fenw;

    FenwickTree(int n_) : n(n_) {
        fenw.resize(n);
        ws.resize(n);
    }

    void update(int x, T v){
        T diff = v - ws[x];
        ws[x] = v;
        while(x < n){
            fenw[x] += diff;
            x |= x + 1;
        }
    }

    T query(int x){
        T sum = 0;
        while(x){
            sum += fenw[x-1];
            x &= x-1;
        }
        return sum;
    }
};

void solve(){ 
    int n, q; cin >> n >> q;
    FenwickTree<ll> v(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        v.update(i, x);
    }
    while(q--){
        int t; cin >> t;
        ll a, b;
        switch(t){
        case 1: 
            cin >> a >> b;
            v.update(a-1, b);
            break;
        case 2:
            cin >> a >> b;
            cout << v.query(b) - v.query(a-1) << nl;
        }
        // for(auto &ele : v.fenw) cout << ele << ' '; cout << nl;
    }
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