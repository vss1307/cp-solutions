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
    vector<T> fenw;

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
        while(x){
            sum += fenw[x-1];
            x &= x-1;
        }
        return sum;
    }
};

void solve(){ 
    int n, q; cin >> n >> q;
    FenwickTree<int> v(n);
    for(int i = 0; i < n; i++) v.update(i, 1);
    while(q--){
        int r; cin >> r;
        cout << v.query(r-1) << ' ';
        v.update(0, -(r));
        v.update(r, (r));
    }
    cout << nl;
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