class Solution {
public:
    int visit[1'00000+5];
    vector<int> adj[1'00000+5];
    int mxLen[1'00000+5][26];
    bool hasCycle;
    
    void update(int idx, string &colors)
    {
        visit[idx] = 1;
        
        mxLen[idx][colors[idx]-'a'] = 1;
        
        for(auto &next : adj[idx])
        {
            if(visit[next] == 0) update(next, colors);
            else if(visit[next] == 1) hasCycle = true;            
            
            for(int i=0;i<26;i++)
            {
                if(i+'a' == colors[idx]) mxLen[idx][i] = max(mxLen[idx][i], 1 + mxLen[next][i]);
                else mxLen[idx][i] = max(mxLen[idx][i], mxLen[next][i]);
            }
        }
        
        visit[idx] = 2;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for(auto &edge : edges) adj[edge[0]].push_back(edge[1]);
        for(int i=0;i<colors.size();i++)
        {
            if(visit[i] == 0) update(i, colors);
        }
        if(hasCycle) return -1;
        
        int ans = 0;
        
        for(int i=0;i<colors.size();i++)
        {
            for(int j=0;j<26;j++) ans = max(ans, mxLen[i][j]);
        }
        
        return ans;
    }
};
