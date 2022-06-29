class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < n; ++j) {
                if(i == j || i + j == n - 1) {
                    if(!grid[i][j])
                        return false;
                } else if(grid[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
