class Solution {
public:
    int parent[1'0000+5];
    
    int find(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        parent[v] = u;
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for(int i=1;i<=n;i++) parent[i] = i;
        
        for(int i=threshold+1;i<=n;i++)
        {
            for(int j=i;j<=n;j+=i) merge(i, j);
        }
        
        vector<bool> ans;
        
        for(auto &query : queries)
        {
            int u = find(query[0]);
            int v = find(query[1]);
            
            if(u == v) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};
