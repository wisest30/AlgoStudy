class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ret = 0;;
        for(auto row = 0; row < n; ++row) {
            for(auto col = 0; col < n; ++col) {
                bool same = true;
                for(auto i = 0; i < n; ++i) {
                    if(grid[row][i] != grid[i][col]) {
                        same = false;
                        break;
                    }
                }
                
                ret += same;
            }
        }
        
        return ret;
    }
};
