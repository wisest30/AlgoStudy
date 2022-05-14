class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        bool dp[100+5][100+5][200+5]{};
        int R = grid.size();
        int C = grid[0].size();
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(i == 0 && j == 0)
                {
                    if(grid[i][j] == '(') dp[i][j][1] = true;
                }
                if(i > 0)
                {
                    for(int k=0;k<=200;k++)
                    {
                        if(grid[i][j] == '(' && k < 200) dp[i][j][k+1] |= dp[i-1][j][k];
                        else if(grid[i][j] == ')' && k > 0) dp[i][j][k-1] |= dp[i-1][j][k];
                    }
                }
                if(j > 0)
                {
                    for(int k=0;k<=200;k++)
                    {
                        if(grid[i][j] == '(' && k < 200) dp[i][j][k+1] |= dp[i][j-1][k];
                        else if(grid[i][j] == ')' && k > 0) dp[i][j][k-1] |= dp[i][j-1][k];
                    }
                }
            }
        }
        
        return dp[R-1][C-1][0];
    }
};
