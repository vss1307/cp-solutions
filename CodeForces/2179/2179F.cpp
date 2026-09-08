/*
 * Author: vss_1307
 * Created: 2025-12-25 18:24:22
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;
constexpr char nl = '\n';
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char next(char c){
    if(c == 'r') return 'g';
    if(c == 'g') return 'b';
    if(c == 'b') return 'r';
}

char prev(char c){
    if(c == 'r') return 'b';
    if(c == 'g') return 'r';
    if(c == 'b') return 'g';
}

void solvef(){ 
    ll n, m; cin >> n >> m;
    vector <vector <ll> > graph(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue <ll> q;
    q.push(0);
    string s(n, 'a');
    s[0] = 'r';
    while(q.size()){
        ll u = q.front(); q.pop();
        for(auto &v : graph[u]){
            if(s[v] != 'a') continue;
            s[v] = next(s[u]);
            q.push(v);
        }
    }
    cout << s << nl;
}

void solves(){
    ll q; cin >> q;
    while(q--){
        ll d; cin >> d;
        string s; cin >> s;
        set <char> st = {'r', 'g', 'b'};
        for(auto &c : s) if(st.find(c) != st.end()) st.erase(c);
        char curr = *st.begin();
        char par = prev(curr);
        for(int i = 0; i < d; i++){
            if(s[i] == par){
                cout << i+1 << nl;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    string s; cin >> s;
    int te; cin >> te;
    while (te--){
        if(s == "first") solvef();
        else solves();
    }
}