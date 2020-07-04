vector<int> G;
void init(int n) {
    G.resize(n);
    iota(G.begin(), G.end(), 0);
}

int get_group(int x) {
    if(G[x] == x)
        return x;
    return G[x] = get_group(G[x]);
}

void merge_group(int x, int y) {
    int gx = get_group(x);
    int gy = get_group(y);
    if(gx == gy) return;
    if(gx > gy)
        swap(gx, gy);
    G[gx] = G[gy];
}

struct edge{
    int u, v, w, idx, status;
};

class Solution {
public:
    int dfs(vector<vector<int>>& edges, vector<bool>& visited, int cur) {
        if(visited[cur]) return 0;
        visited[cur] = true;
        auto ret = 1;
        for(auto i = 0; i < edges[cur].size(); ++i)
            ret += dfs(edges, visited, edges[cur][i]);
        
        return ret;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        auto E = vector<edge>();
        for(auto i = 0; i < m; ++i)
            E.push_back({edges[i][0], edges[i][1], edges[i][2], i, 0});

        sort(E.begin(), E.end(), [&](auto& x, auto& y) {
                return x.w < y.w;
            }
        );

        init(n);
        for(auto& e : E) {
            if(get_group(e.u) != get_group(e.v)) {
                e.status = 1;
                merge_group(e.u, e.v);
            }
        }

        set<int> ret1, ret2;
        for(auto i = 0; i < E.size(); ++i) {
            if(!E[i].status) continue;
            bool critical = true;
            for(auto j = 0; j < E.size(); ++j) {
                if(E[i].w != E[j].w) continue;
                if(E[i].status == E[j].status) continue;

                swap(E[i].status, E[j].status);
                auto my_edges = vector<vector<int>>(n);
                for(auto& e : E) {
                    if(e.status) {
                        my_edges[e.u].push_back(e.v);
                        my_edges[e.v].push_back(e.u);
                    }
                }
                auto visited = vector<bool>(n);
                if(dfs(my_edges, visited, 0) == n) {
                    critical = false;
                    ret2.insert(E[i].idx);
                    ret2.insert(E[j].idx);
                }
                swap(E[i].status, E[j].status);
            }
            if(critical)
                ret1.insert(E[i].idx);
        }

        auto ret = vector<vector<int>>{vector<int>(ret1.begin(), ret1.end()),
                                        vector<int>(ret2.begin(), ret2.end())};
        return ret;
    }
};
