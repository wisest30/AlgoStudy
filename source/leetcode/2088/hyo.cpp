class Solution {
public:
    int f(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ret = 0;
        
        auto dp = vector<vector<int>>(r, vector<int>(c));        
        for(auto y = 0; y < r; ++y) {
            auto L = grid[y];
            for(auto x = 1; x < c; ++x)
                if(grid[y][x]) L[x] += L[x-1];
            
            auto R = grid[y];
            for(auto x = c-2; x >= 0; --x)
                if(grid[y][x]) R[x] += R[x+1];
            
            for(auto x = 0; x < c; ++x) {
                int prev = y == 0 ? 0 : dp[y-1][x];
                dp[y][x] = min(min(L[x], R[x]), prev + 1);
                if(dp[y][x] > 1)
                    ret += max(0, dp[y][x] - 1);
            }
        }
        return ret;
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        auto grid2 = grid;
        for(auto i = 0; i < grid2.size() / 2; ++i)
            swap(grid2[i], grid2[grid2.size() - 1 - i]);
        
        return f(grid) + f(grid2);
    }
};
