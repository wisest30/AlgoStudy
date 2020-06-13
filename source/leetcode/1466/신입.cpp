class Solution {
public:
    vector<int> adj[50000+5];
    vector<int> radj[50000+5];
    int ans;
    
    void dfs(int root, int parent)
    {
        for(auto &next : radj[root])
        {
            if(next == parent) continue;
            dfs(next, root);
        }
        for(auto &next : adj[root])
        {
            if(next == parent) continue;
            ans++;
            dfs(next, root);
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
        for(auto &connection : connections) 
        {
            adj[connection[0]].push_back(connection[1]);
            radj[connection[1]].push_back(connection[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
