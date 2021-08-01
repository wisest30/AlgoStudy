#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> G;
vector<bool> visited, inPath;
vector<int> ans;

void dfs(int cur) {
    if(visited[cur]) {
        if(inPath[cur])
            ans[cur] = 3;
        else if(ans[cur] != 3)
            ans[cur] = 2;

        return;
    }

    visited[cur] = true;
    inPath[cur] = true;
    ans[cur] = 1;

    for(auto nxt : G[cur])
        dfs(nxt);
    
    inPath[cur] = false;
}

void dfs2(int cur, int val) {
    if(visited[cur])
        return;

    visited[cur] = true;

    ans[cur] = max(ans[cur], val);
    for(auto nxt : G[cur])
        dfs2(nxt, val);
}

void solve(int TestCase) {
    cin >> n >> m;

    G = vector<vector<int>>(n);
    visited = vector<bool>(n);
    inPath = vector<bool>(n);

    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    ans = vector<int>(n);
    dfs(0);

    for(auto val = 2; val <= 3; ++val) {
        visited = vector<bool>(n);
        for(auto u = 0; u < n; ++u)
            if(ans[u] == val)
                dfs2(u, val);
    }

    for(auto& x : ans)
        if(x == 3)
            x = -1;

    for(auto x : ans)
        cout << x << " ";
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
