class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    int oneCnt;
    int twoCnt;
    
    void grid1dfs(vector<vector<int>>& grid1, int r, int c)
    {
        grid1[r][c] = 2;
        
        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= grid1.size() || nc >= grid1[0].size()) continue;
            if(grid1[nr][nc] == 1) grid1dfs(grid1, nr, nc);
        }
    }
    
    void grid2dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c)
    {
        grid2[r][c] = 2;
        oneCnt++;
        if(grid1[r][c] == 2) twoCnt++;
        
        for(int i=0;i<4;i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= grid2.size() || nc >= grid2[0].size()) continue;
            if(grid2[nr][nc] == 1) grid2dfs(grid1, grid2, nr, nc); 
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int R = grid1.size();
        int C = grid1[0].size();
        int ans = 0;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid1[i][j] == 1) grid1dfs(grid1, i, j);
            }
        }
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid2[i][j] == 1)
                {
                    oneCnt = 0;
                    twoCnt = 0;
                    
                    grid2dfs(grid1, grid2, i, j);
                    
                    if(oneCnt == twoCnt) ans++;
                }
            }
        }
        
        return ans;
    }
};
