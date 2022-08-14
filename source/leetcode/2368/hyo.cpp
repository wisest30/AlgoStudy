class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        auto g = vector<vector<int>>(n);
        unordered_set<int> rs(restricted.begin(), restricted.end());
        for(auto& e : edges) {
            if(rs.count(e[0]) || rs.count(e[1]))
                continue;
            
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int ret = 0;
        function<void(int, int)> dfs = [&](int cur, int prev) {
            ++ret;
            for(auto nxt : g[cur])
                if(nxt != prev)
                    dfs(nxt, cur);
        };
        
        dfs(0, -1);
        
        return ret;
    }
};
