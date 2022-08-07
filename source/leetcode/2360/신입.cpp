class Solution {
public:
    enum Status
    {
        NON_VISITED,
        IN_STACK,
        VISITED
    };
    
    vector<int> edges;
    int status[1'00000+5];
    int visitNum[1'00000+5];
    int cnt;
    int n;
    int ans = -1;
    
    void dfs(int cur)
    {
        if(status[cur] == VISITED) return;
        
        status[cur] = IN_STACK;
        visitNum[cur] = cnt++;
        
        if(edges[cur] != -1)
        {
            int nxt = edges[cur];
            if(status[nxt] == NON_VISITED) dfs(nxt);
            else if(status[nxt] == IN_STACK) ans = max(ans, visitNum[cur] - visitNum[nxt] + 1);
        }
        
        status[cur] = VISITED;
    }
    
    int longestCycle(vector<int>& edges) {
        this->edges = edges;
        n = edges.size();
        
        for(int i=0;i<n;i++) dfs(i);
        return ans;
    }
};
