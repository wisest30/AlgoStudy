#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// MCMF(Minumum Cost Maximum Flow)
struct Edge
{
    int to;
    ll cap, cost;
    Edge *back_edge;

    Edge(int to, ll cap, ll cost) : to(to), cap(cap), cost(cost), back_edge(nullptr) {}
};

struct Node
{
    vector<Edge *> edges;
};

int n;
vector<vector<ll>> ahl;
int s, t;
vector<Node> nodes;
// key : {from node, to node}. (u, v) -> Edge.
map<pair<int, int>, Edge *> edge_map;

void input()
{
    cin >> n;
    ahl = vector<vector<ll>>(n, vector<ll>(3));
    for (auto i = 0; i < 3; ++i)
        for (auto &v : ahl)
            cin >> v[i];
}

void make_edge(int from, int to, ll cap, ll cost)
{
    nodes[from].edges.push_back(new Edge(to, cap, cost));
    nodes[to].edges.push_back(new Edge(from, 0, -cost));
    nodes[from].edges.back()->back_edge = nodes[to].edges.back();
    nodes[to].edges.back()->back_edge = nodes[from].edges.back();
    edge_map[make_pair(from, to)] = nodes[from].edges.back();
    edge_map[make_pair(to, from)] = nodes[to].edges.back();
}

void make_graph()
{
    nodes.resize(2 * n + 2);
    s = 2 * n, t = 2 * n + 1;
    for (auto u = 0; u < n; ++u)
        make_edge(s, u, ahl[u][2] - (u > 0), ahl[u][1]);
    for (auto u = 0; u < n; ++u)
        for (auto v = n + u + 1; v < 2 * n; ++v)
            make_edge(u, v, 1, -(ahl[u][0] ^ ahl[v - n][0]));
    for (auto v = n; v < 2 * n; ++v)
        make_edge(v, t, 1, ahl[v - n][1]);
}

// Shortest Path Fast Algorithm
// return value : (path, minum cost)
pair<vector<int>, ll> SPFA()
{
    vector<ll> dist(nodes.size(), INT64_MAX);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    vector<bool> in_que(nodes.size());
    in_que[s] = true;
    vector<int> prev_node(nodes.size());
    prev_node[s] = -1;

    while (!que.empty())
    {
        auto u = que.front();
        que.pop(), in_que[u] = false;
        for (auto &e : nodes[u].edges)
        {
            if (e->cap == 0)
                continue;

            auto v = e->to;
            if (dist[v] > dist[u] + e->cost)
            {
                dist[v] = dist[u] + e->cost;
                prev_node[v] = u;
                if (!in_que[v])
                    que.push(v), in_que[v] = true;
            }
        }
    }

    if (dist[t] == INT64_MAX)
        return make_pair(vector<int>{}, INT64_MAX);

    vector<int> path;
    path.push_back(t);
    while (prev_node[path.back()] != -1)
        path.push_back(prev_node[path.back()]);
    reverse(path.begin(), path.end());

    return {path, dist[t]};
}

ll solve_mcmf()
{

    ll total_cost = 0;
    while (true)
    {
        auto [path, cost] = SPFA();
        if (path.empty())
            break;
        total_cost += cost;
        for (auto i = 0; i + 1 < path.size(); ++i)
        {
            auto u = path[i], v = path[i + 1];
            auto *edge = edge_map[make_pair(u, v)];
            auto *bedge = edge->back_edge;
            edge->cap--, bedge->cap++;
        }
    }
    return total_cost;
}

void solve(int TestCase)
{
    input();
    sort(ahl.begin(), ahl.end());
    reverse(ahl.begin(), ahl.end());
    make_graph();
    auto ans = -solve_mcmf();
    cout << ans << endl;
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
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}
