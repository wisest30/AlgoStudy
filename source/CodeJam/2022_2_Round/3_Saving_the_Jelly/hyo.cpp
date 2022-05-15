#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;

void solve(int TestCase) {
    int n;
    cin >> n;

    vector<pair<ll, ll>> pos(2 * n + 1);
    for(auto& p : pos) cin >> p.first >> p.second;

    // [0, n) : child
    // n : jelly
    // [n+1, 2 * n + 1) : sweet
    // 2 * n + 1 : source
    // 2 * n + 2 : sink
    auto g = vector<vector<int>>(2 * n + 3);
    auto C = vector<vector<int>>(2 * n + 3, vector<int>(2 * n + 3));
    auto f = vector<vector<int>>(2 * n + 3, vector<int>(2 * n + 3));
    for(auto u = 0; u < n; ++u) {
        g[u].resize(n+1);
        iota(g[u].begin(), g[u].end(), n);
        sort(g[u].begin(), g[u].end(), [&](auto l, auto r) {
            auto d0 = (pos[u].first - pos[l].first) * (pos[u].first - pos[l].first)
                    + (pos[u].second - pos[l].second) * (pos[u].second - pos[l].second);
            auto d1 = (pos[u].first - pos[r].first) * (pos[u].first - pos[r].first)
                    + (pos[u].second - pos[r].second) * (pos[u].second - pos[r].second);
            
            return d0 == d1 ? l > r : d0 < d1;
        });

        while(g[u].back() != n)
            g[u].pop_back();
        g[u].pop_back();

        for(auto v : g[u]) {
            g[v].push_back(u);
            C[u][v] = 1;
        }
    }

    for(auto v = 0; v < n; ++v) {
        g[2 * n + 1].push_back(v);
        C[2 * n + 1][v] = 1;
    }

    for(auto u = n + 1; u < 2 * n + 1; ++u) {
        g[u].push_back(2 * n + 2);
        C[u][2 * n + 2] = 1;
    }

    vector<int> choice(n);
    function<bool(int, vector<bool>&)> dfs = [&](auto cur, auto& visited) {
        if(cur == 2 * n + 2)
            return true;
        if(visited[cur])
            return false;
        visited[cur] = true;

        for(auto nxt : g[cur]) {
            if(f[cur][nxt] < C[cur][nxt]) {
                f[cur][nxt]++;
                f[nxt][cur]--;
                
                auto sub_ret = dfs(nxt, visited);
                if(sub_ret) {
                    if(cur < n)
                        choice[cur] = nxt;
                    return true;
                }
                f[cur][nxt]--;
                f[nxt][cur]++;
            }
        }

        return false;
    };

    int maximum_flow = 0;
    while(true) {
        auto visited = vector<bool>(2 * n + 3);
        if(dfs(2 * n + 1, visited)) {
            maximum_flow++;
        } else {
            break;
        }
    }

    if(maximum_flow == n) {
        cout << "POSSIBLE" << endl;
        for(auto& edges : g) {
            reverse(edges.begin(), edges.end());
        }

        vector<bool> used(2 * n + 3);
        for(auto cnt = 0; cnt < n; ++cnt) {
            for(auto u = 0; u < n; ++u) {
                if(used[u]) continue;
                while(used[g[u].back()])
                    g[u].pop_back();
                
                if(g[u].back() == choice[u]) {
                    used[u] = used[g[u].back()] = true;
                    cout << (u + 1) << " " << (g[u].back() - n + 1) << "\n";
                    break;
                }
            }
        }
    }
    else
        cout << "IMPOSSIBLE" << endl;
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
