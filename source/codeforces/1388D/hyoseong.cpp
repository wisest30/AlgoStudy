#include<bits/stdc++.h>
 
using namespace std;

template <typename CostType>
class graph {
public:
    struct edge {
        int from;
        int to;
        CostType cost;
    };

    vector<vector<int>> nodes;
    vector<edge> edges;

    graph(int node_cnt_) 
    : nodes(node_cnt_)
    {}

    int get_node_cnt() { return nodes.size(); }
    int get_edges_cnt() { return edges.size(); }

    virtual int add(int from, int to, CostType cost) = 0;
};

template <typename CostType>
class digraph : public graph<CostType> {
public:
    using graph<CostType>::nodes;
    using graph<CostType>::edges;
    using graph<CostType>::get_node_cnt;
    using graph<CostType>::get_edges_cnt;

    digraph(int node_cnt_) : graph<CostType>(node_cnt_) {}
    int add(int from, int to, CostType cost = 1) {
        assert(0 <= from && from < get_node_cnt());
        assert(0 <= to && to < get_node_cnt());

        auto edge_idx = get_edges_cnt();
        nodes[from].push_back(edge_idx);
        edges.push_back({from, to, cost});
        return edge_idx;
    }

    digraph<CostType> get_reverse_digraph() {
        auto ret = digraph<CostType>(get_node_cnt());
        for(auto& e : edges)
            ret.add(e.to, e.from, e.cost);
        
        return ret;
    }
};

template <typename CostType>
vector<int> get_topsort(digraph<CostType> &g) {
    vector<int> in_degree(g.get_node_cnt());
    for (auto& e : g.edges)
        in_degree[e.to]++;

    vector<int> ret;
    for (int i = 0; i < g.get_node_cnt(); i++) {
        if (in_degree[i] == 0)
            ret.push_back(i);
    }

    for(auto i = 0; i < ret.size(); ++i)
    {
        int cur = ret[i];
        for(auto edge_idx : g.nodes[cur]) {
            auto& e = g.edges[edge_idx];
            if(--in_degree[e.to] == 0)
                ret.push_back(e.to);
        }
    }

    // invalid - cycle
    if(ret.size() != g.get_node_cnt())
       return {};

    return ret;
}

int n;
long long A[200000], B[200000];
long long ans = 0;

void solve(int TestCase) {
    cin >> n;
    digraph<int> g(n);
    for(auto i = 0; i < n; ++i) cin >> A[i];
    for(auto i = 0; i < n; ++i) {
        cin >> B[i];
        B[i]--;
        if(B[i] < 0) continue;
        int u = i, v = B[i];
        g.add(u, v);
    }

    auto C = get_topsort(g);
    auto ret = vector<int>{};
    auto ret2 = vector<int>{};
    for(auto i : C) {
        ans += A[i];
        if(A[i] > 0 && B[i] >= 0) {
            A[B[i]] += A[i];
            ret.push_back(i);
        }
        else
            ret2.push_back(i);
    }
    
    cout << ans << endl;

    for(auto i = (int)ret2.size() - 1; i >= 0; --i) ret.push_back(ret2[i]);
    for(auto r : ret) cout << (r+1) << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
//        cout << "Case #"<< i << ": ";
        solve(i);
    }
}
