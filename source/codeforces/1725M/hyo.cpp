#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_BIT = 31;

void solve(int TestCase)
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> g(2 * n);
    for (auto i = 0; i < m; ++i)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        g[u].push_back({v, w});
        g[v + n].push_back({u + n, w});
    }
    for (auto i = 0; i < n; ++i)
        g[i].push_back({i + n, 0});

    vector<ll> D(2 * n, INT64_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d >= D[cur])
            continue;
        D[cur] = d;
        for (auto &e : g[cur])
            pq.push({d + e.second, e.first});
    }

    vector<ll> ans(n);
    for (auto i = 0; i < n; ++i)
    {
        ans[i] = min(D[i], D[i + n]);
        if (ans[i] == INT64_MAX)
            ans[i] = -1;
    }

    for (auto i = 1; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    for (auto i = 1; i <= t; ++i)
    {
        // cout << "Case #"<< i << ": ";
        solve(i);
    }
}
