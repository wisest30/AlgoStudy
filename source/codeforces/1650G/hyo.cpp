#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

// (distance, count)
vector<pair<ll, ll>> bfs(vector<vector<int>> &g, int start) {
    auto ret = vector<pair<ll, ll>>(g.size(), {-1, -1});

    ret[start] = {0, 1};

    queue<int> que;
    que.push(start);

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();

        for(auto nxt : g[cur]) {
            if(ret[nxt].first == -1) {
                ret[nxt].first = ret[cur].first + 1;
                ret[nxt].second = ret[cur].second;
                que.push(nxt);
            } else if(ret[nxt].first == ret[cur].first + 1) {
                ret[nxt].second += ret[cur].second;
                ret[nxt].second %= MOD;
            } 
        }
    }

    return ret;
}

void solve(int TestCase) {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--, t--;

    vector<vector<int>> g(n);
    for(auto i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto d0 = bfs(g, s);
    auto d1 = bfs(g, t);

    auto min_dist = d0[t].first, ret = d0[t].second;
    for(auto u = 0; u < n; ++u) {
        for(auto v : g[u]) {
            if(d0[u].first == d0[v].first && d0[u].first + d1[v].first == min_dist) {
                ret += d0[u].second * d1[v].second % MOD;
                ret %= MOD;
            }
        }
    }

    cout << ret << endl;
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
