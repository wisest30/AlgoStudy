static bool dp[101][101][101];

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')')
            return false;
        
        int r = grid.size(), c = grid[0].size();
        for(auto y = 0; y < r; ++y)
            for(auto x = 0; x < c; ++x)
                grid[y][x] = grid[y][x] == '(' ? 1 : -1;
        
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = true;
        
        for(auto y = 0; y < r; ++y) {
            for(auto x = 0; x < c; ++x) {
                for(auto p = 0; p <= 100; ++p) {
                    if(dp[y][x][p]) {
                        if(y + 1 < r && p + grid[y+1][x] >= 0 && p + grid[y+1][x] <= 100)
                            dp[y+1][x][p + grid[y+1][x]] = true;
                        if(x + 1 < c && p + grid[y][x+1] >= 0 && p + grid[y][x+1] <= 100)
                            dp[y][x+1][p + grid[y][x+1]] = true;
                    }
                }
            }
        }
        
        return dp[r-1][c-1][0];
    }
};
