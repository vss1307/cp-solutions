/*
 * Author: vss_1307
 * Created: 2026-04-18 17:40:24
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){ 
    string a, b; cin >> a >> b;
    auto rem = [](string s)->string{
        string res = "";
        for(int i = 0; i < s.size(); i++){
            // cerr << i << ' ' << res << ' ' << s << nl;
            ll j = i+2;
            if(res.size() && res.back() == '(' && i+1 < s.size() && s.substr(i, 2) == "xx"){
                while(j < s.size() && res.size() && res.back() == '(' && s[j] == ')'){
                    res.pop_back();
                    j++;
                }
                res += "xx";
                i = j-1;
            }
            else res.push_back(s[i]);
        }
        return res;
    };
    if(rem(a) == rem(b)) cout << "Yes" << nl;
    else cout << "No" << nl;
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