class Solution {
public:
    int alphabetSubtree[100000+5][26];
    vector<int> adj[100000+5];
    
    void dfs(int parent, int here, string& labels)
    {
        for(int i=0;i<26;i++) alphabetSubtree[here][i] = 0;
        alphabetSubtree[here][labels[here] - 'a']++;
        
        for(int next : adj[here])
        {
            if(next == parent) continue;
            dfs(here, next, labels);
            
            for(int i=0;i<26;i++) alphabetSubtree[here][i] += alphabetSubtree[next][i];
        }
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        memset(alphabetSubtree, 0, sizeof(alphabetSubtree));
        
        for(auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        dfs(-1, 0, labels);
        
        vector<int> ans;
        
        for(int i=0;i<n;i++) ans.push_back(alphabetSubtree[i][labels[i]-'a']);
        
        return ans;
    }
};
