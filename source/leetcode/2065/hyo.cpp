class Solution {
public:
    int n, maxTime, ans;
    vector<vector<array<int, 2>>> g;
    vector<int> values;
    void dfs(int cur, int time, int score) {
        if(time > maxTime)
            return;
        if(cur == 0)
            ans = max(ans, score);
        
        int s = values[cur];
        values[cur] = 0;
        for(auto [nxt, t] : g[cur])
            dfs(nxt, time + t, score + values[nxt]);
        values[cur] = s;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        n = values.size();
        this->maxTime = maxTime;
        ans = 0;
        g.resize(n);
        this->values = values;
        
        for(auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        
        dfs(0, 0, values[0]);
        return ans;
    }
};
