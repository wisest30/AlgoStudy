class Solution {
public:
    int R;
    int C;
    vector<vector<int>> grid;
    vector<vector<int>> memo;
    
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    
    const int MOD = 1e9+7;
    
    int getMemo(int r, int c)
    {
        if(memo[r][c] != -1) return memo[r][c];
        
        memo[r][c] = 1;
        
        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            
            if(nr >= R || nr < 0 || nc >= C || nc < 0) continue;
            if(grid[nr][nc] < grid[r][c]) memo[r][c] += getMemo(nr, nc);
        }
        
        memo[r][c] %= MOD;
        
        return memo[r][c];
    }
    
    int countPaths(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        this->grid = grid;
        memo = vector<vector<int>>(R, vector<int>(C, -1));
        
        int ans = 0;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                ans += getMemo(i, j);
                ans %= MOD;
            }
        }
        
        return ans;
    }
};
