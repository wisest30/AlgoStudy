class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        auto cost = grid;
        int r = grid.size(), c = grid[0].size();
        for(auto y = 1; y < r; ++y) {
            for(auto x = 0; x < c; ++x) {
                cost[y][x] = INT_MAX;
                for(auto px = 0; px < c; ++px)
                    cost[y][x] = min(cost[y][x], cost[y-1][px] + moveCost[grid[y-1][px]][x] + grid[y][x]);
            }
        }
        
        return *min_element(cost[r-1].begin(), cost[r-1].end());
    }
};
