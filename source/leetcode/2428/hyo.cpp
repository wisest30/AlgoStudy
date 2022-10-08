class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int dy[7] = {-1, -1, -1, 0, 1, 1, 1};
        int dx[7] = {-1, 0, 1, 0, -1, 0, 1};
        int r = grid.size(), c = grid[0].size();
        
        long long ret = 0;
        for(auto y = 1; y + 1 < r; ++y) {
            for(auto x = 1; x + 1 < c; ++x) {
                long long candi = 0;
                for(auto i = 0; i < 7; ++i)
                    candi += grid[y + dy[i]][x + dx[i]];
                
                ret = max(ret, candi);
            }
        }
        return ret;
    }
};
