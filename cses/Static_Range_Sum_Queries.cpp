/*
 * Author: vss_1307
 * Created: 2026-08-21 19:50:32
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
class FenwickTree {
  public:
    vector<T> fenw;
    int n;

    FenwickTree(int n_) : n(n_) {
        fenw.resize(n);
    }

    void update(int x, T v){
        while(x < n){
            fenw[x] += v;
            x |= x + 1;
        }
    }

    T query(int x){
        T sum = 0;
        while(x > 0){
            sum += fenw[x-1];
            x &= x - 1;
        }
        return sum;
    }
};

void solve(){ 
    int n, q; cin >> n >> q;
    FenwickTree<ll> v(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.update(i, x);
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << v.query(r) - v.query(l-1) << nl;
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