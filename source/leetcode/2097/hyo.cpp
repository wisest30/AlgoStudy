class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> D;
        map<int, vector<int>> g;
        for(auto& p : pairs) {
            D[p[0]]++, D[p[1]]--;
            g[p[0]].push_back(p[1]);
        }

        auto start = pairs[0][0];
        for(auto& p : D)
            if(p.second > 0)
                start = p.first;
        
        vector<int> path;
        function<void(int)> dfs = [&](auto cur) {
            while(!g[cur].empty()) {
                auto nxt = g[cur].back();
                g[cur].pop_back();
                dfs(nxt);
            }
            
            path.push_back(cur);
        };
        
        dfs(start);
        reverse(path.begin(), path.end());
        
        auto ret = vector<vector<int>>();
        for(auto i = 0; i < (int)path.size() - 1; ++i)
            ret.push_back({path[i], path[i+1]});
        
        return ret;
    }
};
