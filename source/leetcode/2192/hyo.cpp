class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for(auto& e : edges) {
            g[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        
        vector<bool> visited(n);
        vector<set<int>> res(n);
        function<void(int)> dfs = [&](int cur) {
            for(auto nxt : g[cur]) {
                if(res[nxt].empty())
                    dfs(nxt);
                
                res[cur].insert(nxt);
                res[cur].insert(res[nxt].begin(), res[nxt].end());
            }
        };
        
        for(auto i = 0; i < n; ++i)
            if(indeg[i] == 0)
                dfs(i);
        
        vector<vector<int>> ret(n);
        for(auto i = 0; i < n; ++i)
            ret[i] = vector<int>(res[i].begin(), res[i].end());

        return ret;
    }
};
