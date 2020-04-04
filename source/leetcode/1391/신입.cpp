class Solution {
public:
    bool visit[305][305];
    bool judge(int cur_r, int cur_c, vector<vector<int>> &grid)
    {
        memset(visit, 0, sizeof(visit));
        visit[0][0] = true;
        
        while(true)
        {
            visit[cur_r][cur_c] = true;
            //printf("%d %d\n", cur_r, cur_c);
            
            int before_r = cur_r;
            int before_c = cur_c;
            int next_r = cur_r;
            int next_c = cur_c;
            
            if(grid[cur_r][cur_c] == 1)
            {
                if(cur_c -1 >= 0 && !visit[cur_r][cur_c-1] && (grid[cur_r][cur_c-1] == 1 || grid[cur_r][cur_c-1] == 4 || grid[cur_r][cur_c-1] == 6)) next_c--;
                if(cur_c + 1 < grid[0].size() && !visit[cur_r][cur_c+1] && (grid[cur_r][cur_c+1] == 1 || grid[cur_r][cur_c+1] == 3 || grid[cur_r][cur_c+1] == 5)) next_c++;
            }
            else if(grid[cur_r][cur_c] == 2)
            {
                if(cur_r - 1 >= 0 && !visit[cur_r-1][cur_c] && (grid[cur_r-1][cur_c] == 2 || grid[cur_r-1][cur_c] == 3 || grid[cur_r-1][cur_c] == 4)) next_r--;
                if(cur_r + 1 < grid.size() && !visit[cur_r+1][cur_c] && (grid[cur_r+1][cur_c] == 2 || grid[cur_r+1][cur_c] == 5 || grid[cur_r+1][cur_c] == 6)) next_r++;
            }
            else if(grid[cur_r][cur_c] == 3)
            {
                if(cur_c -1 >= 0 && !visit[cur_r][cur_c-1] && (grid[cur_r][cur_c-1] == 1 || grid[cur_r][cur_c-1] == 4 || grid[cur_r][cur_c-1] == 6)) next_c--;
                if(cur_r + 1 < grid.size() && !visit[cur_r+1][cur_c] && (grid[cur_r+1][cur_c] == 2 || grid[cur_r+1][cur_c] == 5 || grid[cur_r+1][cur_c] == 6)) next_r++;
            }
            else if(grid[cur_r][cur_c] == 4)
            {
                if(cur_c + 1 < grid[0].size() && !visit[cur_r][cur_c+1] && (grid[cur_r][cur_c+1] == 1 || grid[cur_r][cur_c+1] == 3 || grid[cur_r][cur_c+1] == 5)) next_c++;
                if(cur_r + 1 < grid.size() && !visit[cur_r+1][cur_c] && (grid[cur_r+1][cur_c] == 2 || grid[cur_r+1][cur_c] == 5 || grid[cur_r+1][cur_c] == 6)) next_r++;
            }
            else if(grid[cur_r][cur_c] == 5)
            {
                if(cur_c -1 >= 0 && !visit[cur_r][cur_c-1] && (grid[cur_r][cur_c-1] == 1 || grid[cur_r][cur_c-1] == 4 || grid[cur_r][cur_c-1] == 6)) next_c--;
                if(cur_r - 1 >= 0 && !visit[cur_r-1][cur_c] && (grid[cur_r-1][cur_c] == 2 || grid[cur_r-1][cur_c] == 3 || grid[cur_r-1][cur_c] == 4)) next_r--;
            }
            else
            {
                if(cur_c + 1 < grid[0].size() && !visit[cur_r][cur_c+1] && (grid[cur_r][cur_c+1] == 1 || grid[cur_r][cur_c+1] == 3 || grid[cur_r][cur_c+1] == 5)) next_c++;
                
                if(cur_r - 1 >= 0 && !visit[cur_r-1][cur_c] && (grid[cur_r-1][cur_c] == 2 || grid[cur_r-1][cur_c] == 3 || grid[cur_r-1][cur_c] == 4)) next_r--;
            }
            
            cur_r = next_r;
            cur_c = next_c;
            
            if(before_r == cur_r && before_c == cur_c) break;
            if(cur_r == (int)grid.size() - 1 && cur_c == (int)grid[0].size() - 1) break;
        }
        if(cur_r == (int)grid.size() - 1 && cur_c == (int)grid[0].size() - 1) return true;
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        bool ret = false;
        
        if(grid[0][0] == 4)
        {
            if(1 < grid[0].size()) ret = judge(0, 1, grid);
            if(!ret && 1 < grid.size()) ret = judge(1, 0, grid);
        }
        else ret = judge(0, 0, grid);
        
        return ret;
    }
};
