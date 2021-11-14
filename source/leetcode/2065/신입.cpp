class Solution {
public:
    struct Edge
    {
        int v;
        int t;
    };
    
    int visited[1000+5];
    int mxTime;
    vector<Edge> adj[1000+5];
    vector<int> values;
    int ans;
    
    void dfs(int cur, int totalTime, int quality)
    {
        if(totalTime > mxTime) return;
        
        visited[cur]++;
        if(visited[cur] == 1) quality += values[cur];
        
        if(cur == 0) ans = max(ans, quality);
        
        for(auto &nxt : adj[cur])
        {
            dfs(nxt.v, totalTime + nxt.t, quality);
        }
        
        visited[cur]--;
        if(visited[cur] == 0) quality -= values[cur];
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        mxTime = maxTime;
        this->values = values;
        
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        dfs(0, 0, 0);
        
        return ans;
    }
};
