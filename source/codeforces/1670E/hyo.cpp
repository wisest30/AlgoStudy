#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int p;
    cin >> p;

    map<pair<int, int>, int> edge_id;

    auto n = 1 << p;
    vector<vector<int>> g(n);
    for(auto i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);

        edge_id[make_pair(u, v)] = i;
        edge_id[make_pair(v, u)] = i;
    }

    vector<int> node_val(n), edge_val(n-1);
    function<void(int, int)> dfs = [&](int cur, int prev) {
        if(cur == 0) node_val[cur] = 1 << p;
        else if(node_val[prev] & (1 << p)) {
            node_val[cur] = cur;

            auto id = edge_id[make_pair(prev, cur)];
            edge_val[id] = (1 << p) | cur;
        } else {
            node_val[cur] = (1 << p) | cur;

            auto id = edge_id[make_pair(prev, cur)];
            edge_val[id] = cur;
        }

        for(auto nxt : g[cur]) {
            if(nxt == prev) continue;
            dfs(nxt, cur);
        }
    };

    dfs(0, -1);
    cout << 1 << endl;
    for(auto val : node_val) cout << val << " ";
    cout << endl;
    for(auto val : edge_val) cout << val << " " ;
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
