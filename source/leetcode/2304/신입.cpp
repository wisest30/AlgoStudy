class Solution {
public:
    int dp[50+5][50+5];
    vector<int> adj[2500];
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int R = grid.size();
        int C = grid[0].size();
        
        memset(dp, 0x7f, sizeof(dp));
        
        for(int i=0;i<C;i++) dp[0][i] = grid[0][i];
        for(int i=0;i<moveCost.size();i++) 
        {
            for(int j=0;j<moveCost[i].size();j++) adj[i].push_back(moveCost[i][j]);
        }
        
        for(int i=1;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                for(int k=0;k<C;k++)
                {
                    // k column to j column;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + adj[grid[i-1][k]][j] + grid[i][j]);       
                }
            }
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<C;i++) ans = min(ans, dp[R-1][i]);
        
        return ans;
    }
};
