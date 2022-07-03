class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        constexpr int mod = 1e9 + 7;
        int r = grid.size(), c = grid[0].size();
        
        auto dp = vector<vector<long long>>(r, vector<long long>(c));
        vector<vector<int>> orders;
        for(auto y = 0; y < r; ++y)
            for(auto x = 0; x < c; ++x)
                orders.push_back({-grid[y][x], y, x});

        sort(orders.begin(), orders.end());
        
        int dy[4] = {-1, 0, 0, 1};
        int dx[4] = {0, -1, 1, 0};
        long long ret = 0;
        for(auto& o : orders) {
            int y = o[1], x = o[2];
            dp[y][x] = 1;
            
            for(auto i = 0; i < 4; ++i) {
                auto ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= r || nx < 0 || nx >= c || grid[ny][nx] <= grid[y][x]) continue;
                dp[y][x] = (dp[y][x] + dp[ny][nx]) % mod;
            }
            
            ret = (ret + dp[y][x]) % mod;
        }
        
        return ret;
    }
};
