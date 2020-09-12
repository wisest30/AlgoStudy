class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    
    int R;
    int C;
    
    void dfs(vector<vector<int>>& grid, int r, int c)
    {
        grid[r][c] = 0;
        
        for(int i=0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(grid[nr][nc] == 1) dfs(grid, nr, nc);
        }
    }
    
    int countIsland(vector<vector<int>>& grid)
    {
        int ret = 0;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j] == 1)
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ret;
    }
    
    void gridCopy(vector<vector<int>>& dest, vector<vector<int>>& source)
    {
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                dest[i][j] = source[i][j];
    }
    
    int minDays(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        
        vector<vector<int>> newGrid(R, vector<int>(C, 0));
        gridCopy(newGrid, grid);
        
        int res = countIsland(newGrid);
        if(res != 1) return 0;
        
        gridCopy(newGrid, grid);
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(newGrid[i][j] == 1)
                {
                    newGrid[i][j] = 0;
                    res = countIsland(newGrid);
                    if(res != 1) return 1;
                    gridCopy(newGrid, grid);
                }
            }
        }
        
        return 2;
    }
};
