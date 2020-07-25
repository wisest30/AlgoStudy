class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        auto E = vector<vector<pair<double, int>>>(n);
        for(auto i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            auto p = succProb[i];
            E[u].push_back({p, v});
            E[v].push_back({p, u});
        }
        auto visited = vector<bool>(n);
        auto q = priority_queue<pair<double, int>>();
        q.push({1.0, start});
        while(!q.empty()) {
            auto cur = q.top().second;
            auto p = q.top().first; q.pop();
            if(cur == end) return p;
            if(visited[cur]) continue;

            visited[cur] = true;
            for(auto& x : E[cur])
            {
                auto nxt = x.second;
                auto nxt_p = p * x.first;
                q.push({nxt_p, nxt});
            }
        }
        return 0;
    }
};
