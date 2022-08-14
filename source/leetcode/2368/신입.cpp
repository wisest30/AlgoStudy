class Solution {
public:
    vector<int> adj[1'00000+5];
    set<int> restricted;
    int ans;
    
    void dfs(int cur, int parent)
    {
        if(restricted.find(cur) != restricted.end()) return;
        ans++;
        for(int nxt : adj[cur])
        {
            if(nxt == parent) continue;
            dfs(nxt, cur);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        this->restricted = set(restricted.begin(), restricted.end());
        
        dfs(0, -1);
        
        return ans;
    }
};
