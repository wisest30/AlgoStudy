#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        indeg[v]++;
    }

    vector<int> dp(n, -1);
    function<int(int)> dfs = [&](int cur) {
        auto& ret = dp[cur];
        if(ret != -1) return ret;

        ret = 1;
        if(g[cur].size() <= 1) return ret;

        for(auto nxt : g[cur])
            if(indeg[nxt] > 1)
                ret = max(ret, dfs(nxt) + 1);

        return ret;
    };

    auto ret = 0;
    for(auto u = 0; u < n; ++u)
        ret = max(ret, dfs(u));
    
    cout << ret << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
        //cout << "Case #"<< i << ": ";
        solve(i);
    }
}
