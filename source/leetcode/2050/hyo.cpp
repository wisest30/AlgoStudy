class Solution {
public:
    vector<vector<int>> g;
    vector<int> max_time, time;
    
    int dfs(int cur) {
        if(max_time[cur])
            return max_time[cur];
        
        max_time[cur] = time[cur];
        for(auto nxt : g[cur])
            max_time[cur] = max(max_time[cur], dfs(nxt) + time[cur]);
        
        return max_time[cur];
    }
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        g = vector<vector<int>>(n);
        for(auto& r : relations)
            g[r[0]-1].push_back(r[1]-1);

        max_time = vector<int>(n);
        this->time = time;
        
        auto ret = 0;
        for(auto i = 0; i < n; ++i)
            ret = max(ret, dfs(i));
        
        return ret;
    }
};
