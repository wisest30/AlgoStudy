class Solution {
public:
    vector<int> edges, D;
    vector<bool> visited;
    int ret;
    void dfs(int cur, int d) {
        if(visited[cur]) return;
        visited[cur] = true;
        
        D[cur] = d;
        auto nxt = edges[cur];
        if(nxt != -1) { 
            if(D[nxt] != -1)
                ret = max(ret, D[cur] - D[nxt] + 1);
            else 
                dfs(nxt, d + 1);
        }
        D[cur] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        this->edges = edges;
        this->D = vector<int>(n, -1);
        this->visited = vector<bool>(n);
        this->ret = -1;
        for(auto i = 0; i < n; ++i)
            dfs(i, 0);
        
        return ret;
    }
};
