class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<vector<int>>> memo;
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        
        memo = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(k, 0)));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                grid[i][j] %= k;
                
                if(i == 0 && j == 0) memo[i][j][grid[i][j]] = 1;
                
                if(i)
                {
                    for(int l=0;l<k;l++) memo[i][j][l] = (memo[i][j][l] + memo[i-1][j][(l+k-grid[i][j])%k])%MOD;
                }
                
                if(j)
                {
                    for(int l=0;l<k;l++) memo[i][j][l] = (memo[i][j][l] + memo[i][j-1][(l+k-grid[i][j])%k])%MOD;
                }
            }
        }
        
        return memo[r-1][c-1][0];
    }
};
