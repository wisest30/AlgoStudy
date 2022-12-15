#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    auto g = vector<vector<int>>(n);
    for(auto i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ret(n);
    function<void(int, int, int)> dfs = [&](auto cur, auto prev, auto color) {
        ret[cur] = g[cur].size() * color;
        for(auto nxt : g[cur]) {
            if(nxt == prev) continue;
            dfs(nxt, cur, -color);
        }
    };

    dfs(0, -1, 1);
    for(auto x : ret) cout << x << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
