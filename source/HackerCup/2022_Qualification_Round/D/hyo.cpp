#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n, m, q;
    cin >> n >> m >> q;

    auto hash = [](auto u, auto v) {
        return u * 1000000ll + v;
    };

    auto g = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>());
    unordered_map<ll, ll> edges;
    for(auto i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        edges[hash(u, v)] = c;
        edges[hash(v, u)] = c;
    }

    vector<pair<int, int>> query;
    unordered_map<ll, ll> ans;
    for(auto i = 0; i < q; ++i) {
        int x, y;

        cin >> x >> y;
        x--, y--;
        if(x > y) swap(x, y);

        query.push_back({x, y});
        ans[hash(x, y)] = 0;
    }

    for(auto u = 0; u < n; ++u)
        for(auto [v, c] : g[u])
            if(ans.count(hash(u, v)))
                ans[hash(u, v)] = 2 * c;

    vector<int> big_nodes;
    for(auto u = 0; u < n; ++u) {
        if(g[u].size() > 100) {
            big_nodes.push_back(u);
            continue;
        }
        for(auto i = 0; i < g[u].size(); ++i) {
            for(auto j = i+1; j < g[u].size(); ++j) {
                int x = g[u][i].first, y = g[u][j].first;
                int c0 = g[u][i].second, c1 = g[u][j].second;
                if(x > y) swap(x, y);

                ans[hash(x, y)] += min(c0, c1);
            }
        }
    }

    for(auto& p : ans) {
        auto x = p.first / 1000000ll;
        auto y = p.first % 1000000ll;
        for(auto u : big_nodes)
            if(edges.count(hash(u, x)) && edges.count(hash(u, y)))
                p.second += min(edges[hash(u, x)], edges[hash(u, y)]);
    }

    for(auto q : query)
        cout << ans[hash(q.first, q.second)] << " ";
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    for(auto i = 1; i <= t; ++i) {
        cout << "Case #"<< i << ": ";
        solve(i);
    }
}


