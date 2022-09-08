class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int r = mat.size(), c = mat[0].size(), ret = 0;
        for(auto subset = 0; subset < (1 << c); ++subset) {
            if(__builtin_popcount(subset) != cols)
                continue;

            int cnt = 0;
            for(auto y = 0; y < r; ++y) {
                bool add = true;
                for(auto x = 0; x < c; ++x)
                    add &= (subset & (1 << x)) || mat[y][x] == 0;

                cnt += add;
            }
            
            ret = max(ret, cnt);
        }
        
        return ret;
    }
};
