class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        constexpr int MOD = 1e9 + 7;
        int r = grid.size(), c = grid[0].size();
        auto dp = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(k)));
        dp[0][0][grid[0][0] % k] = 1;
        for(auto y = 0; y < r; ++y) {
            for(auto x = 0; x < c; ++x) {
                for(auto i = 0; i < k; ++i) {
                    if(y > 0) dp[y][x][(i + grid[y][x]) % k] = (dp[y][x][(i + grid[y][x]) % k] + dp[y-1][x][i]) % MOD;
                    if(x > 0) dp[y][x][(i + grid[y][x]) % k] = (dp[y][x][(i + grid[y][x]) % k] + dp[y][x-1][i]) % MOD;
                }
            }
        }
        
        return dp[r-1][c-1][0];
    }
};
