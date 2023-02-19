#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

int n, m, s;
vector<vector<int>> g;
vector<bool> visited;
vector<int> path0, path1, prev_, color;

void dfs_back(int cur, vector<int>& path) {
    while(cur != -1) {
        path.push_back(cur);
        cur = prev_[cur];
    }
}

void dfs(int cur, int p, int c) {
    if(visited[cur]) return;
    visited[cur] = true;
    prev_[cur] = p;
    color[cur] = c;

    for(auto nxt : g[cur])
        dfs(nxt, cur, cur == s ? nxt : c);
}

void solve(int TestCase) {
    cin >> n >> m >> s;
    s--;

    g.resize(n);
    visited.resize(n);
    prev_.resize(n);
    fill(prev_.begin(), prev_.end(), -1);
    color.resize(n);
    fill(color.begin(), color.end(), -1);
    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    dfs(s, -1, -1);

    for(auto u = 0; u < n; ++u) {
        if(u != s && color[u] == -1) continue;
        for(auto v : g[u]) {
            if(v == s || color[v] == -1) continue;
            if(u == s && prev_[v] == s) continue;
            if(color[u] != color[v]) {
                cout << "Possible" << endl;

                dfs_back(u, path0);
                dfs_back(v, path1);

                reverse(path0.begin(), path0.end());
                reverse(path1.begin(), path1.end());

                path0.push_back(v);

                cout << path0.size() << endl;
                for(auto x : path0) cout << (x + 1) << " ";
                cout << endl;
                cout << path1.size() << endl;
                for(auto x : path1) cout << (x + 1) << " ";
                cout << endl;
                return;
            }
        }
    }

    cout << "Impossible" << endl;
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
