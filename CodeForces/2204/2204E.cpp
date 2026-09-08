/*
 * Author: vss_1307
 * Created: 2026-03-17 00:38:22
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string s; cin >> s;
    if(s.size() == 1){
        cout << s << nl;
        return;
    }
    vector <ll> freq(10);
    for(auto &x : s){
        freq[x-'0']++;
    }
    auto sum = [](vector <ll> f)->ll{
        ll res = 0;
        for(int i =0; i < 10; i++) res += i * f[i];
        return res;
    };
    auto dig = [](ll x, auto &self)->vector <ll>{
        ll digsum = 0;
        vector <ll> f(10);
        if(x < 10){
            f[x]++;
            return f;
        }
        while(x){
            f[x%10]++;
            digsum += x%10;
            x/=10;
        }
        auto temp = self(digsum, self);
        for(int i = 0; i < 10; i++){
            f[i] += temp[i];
        }
        return f;
    };
    for(int i = 1; i <= 900000; i++){
        ll s = sum(freq);
        vector <ll> f = dig(i, dig);
        ll s1 = sum(f) + i;
        if(s != s1) continue;
        bool check = true;
        for(int j = 0; j < 10; j++){
            if(f[j] > freq[j]) check = false;
        }
        if(check){
            for(int j = 0; j < 10; j++){
                freq[j] -= f[j];
            }
            ll j = 9;
            while(j > -1){
                while(freq[j]--) cout << j;
                j--;
            }
            while(i >= 10){
                cout << i;
                ll digsum = 0;
                while(i){
                    digsum += i%10;
                    i/=10;
                }
                i = digsum;
            }
            cout << i << nl;
            return;
        }
    }
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